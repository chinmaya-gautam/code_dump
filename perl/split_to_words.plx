#!/usr/bin/perl
#split_to_words.plx

use warnings;
use strict;

my $_ = "hello!!! i am chinmaya, how are you?";
my $find = "how";
print "your sentence: ",$_;
my $found = "not found";

print "\n the sentence split to words:\n";
foreach my $word (split){
print $word,"\n";
  if ($word eq $find) {
    $found = "found";
  }
}

print "\nfound $find\n" if $found eq "found";