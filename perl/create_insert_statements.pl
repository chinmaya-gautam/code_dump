#!/usr/bin/perl

my $msg_id, $sender, $receiver, $title, $msg;
my $remains = "";
while (<STDIN>){
    if($_ =~ m/(.*?),(.*)/){
	$msg_id = $1;
	$remains = $2;
    }
    if ($remains =~ m/(.*?),(.*)/){
	$sender = $1;
	$remains = $2;
    }
    if ($remains =~ m/(.*?),(.*)/){
	$receiver = $1;
	$remains = $2;
    }
    if ($remains =~ m/\"(.*?)",(.*
    print "insert into messages values(" +
	
}
