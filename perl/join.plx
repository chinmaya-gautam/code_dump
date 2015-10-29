#!/usr/bin/perl
#join.plx

use warnings;
use strict;

my $passwd = "chinmaya:x:1000:1000::/home/chinmaya:/bin/bash";
my @feilds = split /:/ , $passwd;

print "\n\n\033[32m Login name: $feilds[0]\n\033[0m";
print "\033[33m home directory: $feilds[5]\n\033[0m";
print "\033[34m login shell: $feilds[6]\n\033[0m";

my $passwd2 = join " # ", @feilds;

print "\n\n\033[35m Orignial passwd: $passwd\n\033[0m";
print "\033[36m New passwd: $passwd2\n\033[0m\n\n";