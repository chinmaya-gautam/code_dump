#!/usr/bin/perl
#split.plx

use warnings;
use strict;

my $passwd = "chinmaya:x:1000:1000:chinmaya,,,:/home/chinmaya:/bin/bash";
my @fields = split /:/, $passwd;

print "Login name : $fields[0]\n";
print "userid : $fields[4]\n";
print "home dir : $fields[5]\n";
print "shell : $fields[6]\n";