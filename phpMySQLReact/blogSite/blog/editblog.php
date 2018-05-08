<?php
    // If user is not logged in, then redirect to the login page.
    session_start();
    
    /*
    if (!isset($_SESSION['username'])) {
        header('Location: ./');
    }
    */
    
    // Get the blog text from the database for the logged in user.
    // Connect to database
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=blog", "root", NULL);
    } catch (PDOExecption $e) {
        exit('Database connection failed: ' . $e->getMessage());
    }
    
    // Retrieve the blog text for the logged in user.
    $stmt = $dbh->prepare("SELECT blogtext FROM users WHERE username = :username"); // Sets statement for mysql, increments counter when page is viewed
    $stmt->bindParam(':username', $_SESSION['username']);
    $stmt->execute() or exit("SELECT failed."); // Executes $stmt
    
    // If there is no such user, then redirect to login page.
    if ($stmt->rowCount() == 0) {
        header('Location: ./');
        exit();
    }
   
   // Extract the blog text.
    $row = $stmt->fetch() or exit("fetch failed.");
    $blogtext = $row["blogtext"];
    
?>

<h1>Edit Blog Page</h1>

<p><a href="./">Home</a></p>

<form action="saveblogtext.php" method="post">
    <textarea name="blogtext" rows="12" cols="80"><?php print($blogtext) ?></textarea><br>
    <input type="submit" name="cancel" value="Cancel" size="24" />
    <input type="submit" value="Save" size="24" />
</form>

<!-- <div id="blogtext"><?php print($blogtext) ?></div> -->

<!-- <button onclick="TODO: submit changes">Submit</button> -->