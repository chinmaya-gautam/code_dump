#!/usr/bin/perl
#stacks.plx

use warnings;
use strict;

my $hand;
my @pileofpaper = ("letter", "newspaper", "gas bill", "notepad");

print "here's whats on the desk: @pileofpaper \n";
print "you pick up something off the top of pile.\n";
sleep(5);

$hand = pop @pileofpaper;
print "you have now $hand in your hand\n";
print "you put the $hand away and pick up something else\n";
sleep(5);

$hand = pop @pileofpaper;
print "you picked up a $hand\n";
sleep(5);

print "left on the desk is @pileofpaper\n";
print "you pick of the next thing and throw it away...\n";
pop @pileofpaper;
print "...and you put $hand back on the pile\n";
push @pileofpaper, $hand;
sleep(5);

print "you also put a leaflet and a bank-statment on the pile\n";
push @pileofpaper, "leaflet", "bank statement\n";
print "left on the desk is @pileofpaper\n";

