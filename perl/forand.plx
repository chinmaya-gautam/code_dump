#!/usr/bin/perl
#if && cool case switching trick ...

use warnings;
use strict;

print "please enter a number: ";
my $case = <STDIN>;
chomp $case;
for ($case){
print "loop running for $_ th time\n";		#this shows that the loop runs only once as the range specified consists of one number.
  $_ == 1 && print "your choice was 1\n";
  $_ == 2 && print "your choice was 2\n";
  $_ == 3 && print "your choice was 3\n";
  $_ == 4 && print "your choice was 4\n";
  $_ == 5 && print "your choice was 5\n";
}
