#!/usr/bin/perl

use integer;

$_ =<STDIN>;
chomp $_;
my ($n,$k,$ans);

if(/(\d+)\s+(\d+)/){
$n = $1;
$k = $2;
}

my $in;
$ans=0;
foreach $i (1 .. $n){
  $in = <STDIN>;
  chomp $in;
  if($in%$k == 0){
    $ans++;
  }
}

print $ans;
