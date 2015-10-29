#!/usr/bin/perl
#looploop.plx

use warnings;
use strict;

my @getout = qw(bye quit done exit leave stop finish);

OUTER: while(<STDIN>){
chomp;
my $answer = $_; 
for (@getout){last OUTER if $_ eq $answer};
print "you said $_ \n";
}
