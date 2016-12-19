package OSLNavi_bot;

use strict;
use warnings;
use v5.16;
use Data::Dumper;
use Tie::File;
use local::lib;


use Mojo::Base 'Telegram::Bot::Brain';

has filename => "/tmp/words.csv";
has 'token';
has regex    => sub { return qr/(koala|[Nn]avidad|hate)/};


sub check {
  my ($self, $msg) = @_;
##  say Dumper( $msg );
##  say Dumper( $msg->chat );

  # Busca el regex
  return 0 if !$msg->text;
  if ($msg->text =~ $self->regex ) {
    return 1;
  }
  return 0;
}


sub response {
  my ($self, $msg) = @_;

  # is this a 1-on-1 ?
  my ($word) = ( $msg->text =~ $self->regex );
  tie my @words, 'Tie::File', $self->filename or die "Fichero de palabras roto $!";

  push @words, $word;
}

sub count_words {
  my $self = shift;
  tie my @words, 'Tie::File', $self->filename or die "Fichero de palabras roto $!";
  my %count;
  map( $count{lc($_)}++, @words);
  my $total = 0;
  for my $w (keys %count) {
      $total+=$count{$w};
  }
  say Dumper %count;
  my @numbers;
  say $total;
  for my $w (sort keys %count) {
      say "$w, $count{$w}, $count{$w}/$total";
      push @numbers, 99-int( 100*$count{$w}/$total);
      say Dumper @numbers;
  }
  say Dumper @numbers;
  open( my $port, ">", "/dev/ttyACM0" );
  #  print $port join("",@numbers);
  print $port "115599";
  close $port;
  say join("", @numbers);

}

sub init {
    my $self = shift;
    $self->add_listener(\&check, \&response);
    $self->add_repeating_task(30, \&count_words);
    open my $file, ">", $self->filename;
    close $file;
}

"Merry Xmas";
