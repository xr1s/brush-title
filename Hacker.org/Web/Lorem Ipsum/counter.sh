tr --delete '.,' < lorem.txt | tr ' \r' '\n\n' | sort | uniq --count | sort --numeric-sort --reverse
