#!/usr/bin/perl
#my_grep.plx

use warnings;
use strict;

print "\n\@Argv :",@ARGV;
print "\n scalar \@ARGV:",scalar @ARGV;
print "\n\n";

die "usage my_grep.plx <filename> <word>" unless scalar @ARGV == 2;

my $filename = @ARGV[0];
my $word = @ARGV[1];

print "\nfilename: $filename";
print "\nword : $word\n";

#filename feature to be implemented soon
$_ = "this is a cool sentence written by chinmaya gautam.";
if(/$word/) {print "' $word ' found in sentence.";}