#!/usr/bin/perl
#rhyming.plx

use warnings;
use strict;

die "usage rhyming.plx <wordlist.txt>" unless scalar @ARGV == 1;

print "enter the ending letters of word to be matched: ";
my $rhyme = <STDIN>;
chomp $rhyme;

  while(<>){
    print if /$rhyme$/;
  }
