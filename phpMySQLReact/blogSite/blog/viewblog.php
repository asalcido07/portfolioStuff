<?php
    // If user is not logged in, then redirect to the login page.
    session_start();
    
    /*
    if (!isset($_SESSION['username'])) {
        header('Location: ./');
    }
    */
    
    // Get the blog text from the database for the designated user.
    // Connect to database
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=blog", "root", NULL);
    } catch (PDOExecption $e) {
        exit('Database connection failed: ' . $e->getMessage());
    }
    
    // Retrieve the click count for logged in user.
    $stmt = $dbh->prepare("SELECT blogtext FROM users WHERE username = :username"); // Sets statement for mysql, increments counter when page is viewed
    $stmt->bindParam(':username', $_GET['u']);
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

<h1>Blog Page</h1>

<p><a href="./">Home</a></p>

<div id="blogtext"><?php print($blogtext) ?></div>

<?php if (isset($_SESSION["username"]) and $_SESSION["username"] ==  $_GET['u']) { ?>
    <button onclick="window.location='editblog.php'">Edit</button>
<?php } ?>

<div id="error_message"></div>