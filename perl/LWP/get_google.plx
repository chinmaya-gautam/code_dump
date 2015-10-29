#!/usr/bin/perl

use warnings;
use strict;
use LWP::Simple;

my $page=get("http://www.google.com/");
print $page,"\n";