#!/usr/bin/perl
#converter2

use warnings;
use strict;

my ($value, $from, $to, $rate, %rates);

%rates = (
  pound			=>	1,
  dollars		=>	1.6,
  marks			=>	3.0,
  "french franks"	=>	10.0,
  yen			=>	174.8,
  "swiss franks"	=>	2.43,
  drachma		=>	492.3,
  euro			=>	1.5
);

print "Enter your starting currency:  ";
$from = <STDIN>;
print "Enter your ending currency: ";
$to = <STDIN>;
print "Enter your ammount: ";
$value = <STDIN>;

chomp($value, $to, $from);

if (not exists $rates{$to}){
  die "I don't know anything about $to";
}

if (not exists $rates{$from}){
  die "I don't know anything about $from";
}

$rate = $rates{$to} / $rates{$from};
print "$value $from is ", $value*$rate," $to \n";