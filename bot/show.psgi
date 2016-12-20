use Dancer2;

use strict;
use warnings;
use v5.16;
use Tie::File;
use local::lib;

set 'file' =>  "/tmp/words.csv";
set content_type => 'application/json';

get '/' => sub {
  tie my @words, 'Tie::File', setting('file') or die "Fichero de palabras roto $!";
  my %count;
  map( $count{lc($_)}++, @words);
  encode_json(\%count);
};
dance;
