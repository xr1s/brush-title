grep --only-matching '\<[[:alpha:]]\{9\}\>' rfc3280.txt | sort | uniq --count | sort --numeric-sort
