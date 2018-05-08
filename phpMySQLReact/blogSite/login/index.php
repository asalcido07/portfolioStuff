<?php
    session_start();
    if (isset($_SESSION['username'])) {
        header('Location: clickme.php');
        exit();
    }
?>

<h1>Login Page</h1>

<form action="login.php" method="post">
    Username: <input type="text"     value = "fred" name="username" size="36" /> <br>
    Password: <input type="password" value = "1234"  name="password" size="36" /> <br>
              <input type="submit"   value = "Submit" />
</form>