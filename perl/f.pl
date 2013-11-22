#!/usr/bin/perl

use strict;
use warnings;

my $regexv = qr|\b((int\|float)\s[A-Z, a-z, _]\w*(?!\())\b|;
my $regexf = qr|\b((int\|float)\s[A-Z, a-z, _]\w*)\b|;

my $file = $ARGV[0];
open(FILE, $file);

open(OUT, ">output.txt");

if($ARGV[1] eq "v")
{
	while(<FILE>)
	{
		while (/$regexv/g)
		{
			print OUT "$1\t$.\n";
		}
	}
}
elsif($ARGV[1] eq "f")
{
	while(<FILE>)
	{
		while (/$regexf/g)
		{
			print OUT "$1\t$.\n";
		}
	}
}
else
{
	print "Invalid argument\n";
}
