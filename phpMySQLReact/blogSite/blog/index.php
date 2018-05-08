<?php
    session_start();
    
    // Connect to the database
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=blog", "root", NULL);
    } catch (PDOExecption $e) {
        exit('Database connection failed: ' . $e->getMessage());
    }
    
    // Retrieve the click count for logged in user.
    $stmt = $dbh->prepare("SELECT username FROM users"); // Sets statement for mysql, increments counter when page is viewed
    $stmt->execute() or exit("SELECT failed."); // Executes $stmt
    
?>

<h2>Avaiable Blogs</h2>

<ul>
<?php
    foreach ($stmt as $row) {
        $u = $row['username'];
        echo '<li><a href="viewblog.php?u=' . $u . '">' . $u . '</a></li>';
    }
?>
</ul>

<?php if (isset($_SESSION["username"])) { ?>
    <form action="logout.php" method="post">
            <input type="submit" value="logout" />
    </form>
<?php } else { ?>
    <h1>Login Page</h1>
    
    <form action="login.php" method="post">
        Username: <input type="text"     value = "fred" name="username" size="36" /> <br>
        Password: <input type="password" value = "1234"  name="password" size="36" /> <br>
                  <input type="submit"   value = "Login" />
    </form>
<?php } ?>