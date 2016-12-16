package OSLNavi_bot;

use strict;
use warnings;
use v5.14;
use Data::Dumper;

use Mojo::Base 'Telegram::Bot::Brain';
 
has 'token';
has regex     => sub { return qr/(koala|[Nn]avidad|PHP)/};

sub check {
  my ($self, $msg) = @_;
  say Dumper( $msg );
  say Dumper( $msg->chat );

  # Busca el regex
  if ($msg->text =~ $self->regex ) {
    return 1;
  }
  return 0;
}


sub response {
  my ($self, $msg) = @_;

  # is this a 1-on-1 ?
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
}

"Merry Xmas";
