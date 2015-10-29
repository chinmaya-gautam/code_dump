#!/usr/bin/perl
#modified converter

use warnings;
use strict;

my ($from, $to, $rate, $value, %rates, $correct, $fromexists, $toexists);

%rates = (
  INR => '1',
  USD => '45',
  ASD => '38',
  GBP => '78',
  YEN => '1.5'
);

$correct = 0;

  print "enter your value: ";
  $value = <STDIN>;
while(1){
  print "enter starting currency code: ";
  $from = <STDIN>;
  print "enter final currency code: ";
  $to = <STDIN>;
  chomp ($value, $from, $to);

#check if the initial and final currency codes are present in the hash
  for (keys %rates){
    if($from eq $_){
      $fromexists = 1;
  }

    if($to eq $_){
      $toexists = 1;
  }
}
last if ($fromexists && $toexists);
print "please enter a valid currency code: ";
for (keys %rates){
print "$_ \n";
}
};

$rate = $rates{$from} / $rates{$to};

print "\n$value in $from is ",$rate * $value," in $to\n";