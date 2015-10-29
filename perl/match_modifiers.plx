#!/usr/bin/perl
#match_modifiers.plx

use warnings;
use strict;

my $sentence = "Ok, this is a test sentence, testing testing testing 1 2 3...";

print "does it contain a 4 letter word?:";
if ($sentence =~ /\b\w\w\w\w\b/){
print " yes\n"; 
}
else{
print " no\n";
}

print "does it contain a 5 letter word?:";
if ($sentence =~ /\b\w\w\w\w\w\b/){
print " yes\n"; 
}
else{
print " no\n";
}

print "does it contain any number?:";
if ($sentence =~ /\d/){
print " yes\n"; 
}
else{
print " no\n";
}
