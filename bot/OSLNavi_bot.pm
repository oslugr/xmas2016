package OSLNavi_bot;

use strict;
use warnings;
use v5.16;
use Data::Dumper;
use Tie::File;

use Mojo::Base 'Telegram::Bot::Brain';

has filename => "/tmp/words.csv";
has 'token';
has regex    => sub { return qr/(koala|[Nn]avidad|PHP)/};


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
  if ($msg->chat->is_user) {
    $self->send_message_to_chat_id($msg->chat->id, "Dijiste la palabra");
  }
  else {   # group chat
    $self->send_message_to_chat_id($msg->chat->id, "La palabra ha sido dicha");
  }
}

sub init {
    my $self = shift;
    $self->add_listener(\&check, \&response);
    open my $file, ">", $self->filename;
    close $file;
}

"Merry Xmas";
