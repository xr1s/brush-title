<?php

if (!empty($_GET['set'])) {
    file_put_contents('hacker.org', $_GET['set'] . "\n", FILE_APPEND);
}
if (!empty($_GET['get'])) {
    $set = file_get_contents('hacker.org');
    echo strpos($set, $_GET['get']) !== FALSE ? 'yes' : 'no';
}

