#!/usr/bin/perl
#password.plx

use warnings;
use strict;

my $password="foxtrot";

print "enter password to continue: ";
my $input = <STDIN>;

chomp $input;
if ($password eq $input) {
  print "correct password. welcome user!\n";
}
else{
  print "incorrect password\n";
}