#!/usr/bin/perl

use strict;
use warnings;
use Switch;

open my $search_file, '<', $ARGV[2]   or die "Can't open search file: $!";
open my $OUT, '>', $ARGV[4] or die "can't open write file: $!";

my $regexv = qr|\b((int\|float)\s[A-Z, a-z, _]\w*(?!\())\b|;
my $regexf = qr|\b((int\|float)\s[A-Z, a-z, _]\w*)\b|;

while (<$search_file>)
{
	switch($ARGV[0])
    	{
    		case "-v"
		{
			while (/$regexv/g)
        		{	
	        		print $OUT "$1\t$.\n";
			}
		}
		case "-f"
		{
			while (/$regexf/g)
			{
				print $OUT "$1\t$.\n";
			}
		}
		else
		{
			print "Invalid command line argument";
		}
	}
}
