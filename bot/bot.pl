#!/usr/bin/env perl

use strict;
use warnings;

use local::lib;

use OSLNavi_bot;

use v5.14;

my $token = shift || die "No token";
my $bot = OSLNavi_bot->new( token => $token );
$bot->think;  # this will block unless there is already an event
              # loop runningpackage OSLNavi_bot;

