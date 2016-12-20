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
  my @numbers;
  say $total;
  for my $w (sort keys %count) {
      push @numbers, int( 100*(1-$count{$w}/$total));
  }
  open( my $port, ">", "/dev/ttyACM0" );
  print $port join("",@numbers);
  close $port;

}

sub init {
    my $self = shift;
    $self->add_listener(\&check, \&response);
    $self->add_repeating_task(10, \&count_words);
    open my $file, ">", $self->filename;
    close $file;
}

"Merry Xmas";
