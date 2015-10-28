#!/usr/bin/perl

use integer;

my $T = <STDIN>;
chomp $T;

my ($i,$num);

for my $i (1 .. $T){

$num = <STDIN>;
chomp $num;
my $n=5;
my $ans=0;
while($n<=$num){
$ans += $num/$n;
$n*=5;
}
print "$ans\n";
}