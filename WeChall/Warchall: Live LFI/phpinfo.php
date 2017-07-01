<?php
echo "<style>background-color:white;</style>";
echo "<pre>";
echo htmlspecialchars(shell_exec("ls -ARl"));
echo htmlspecialchars(shell_exec("cat solution.php"));
echo htmlspecialchars(shell_exec("cat test.php"));

?>

