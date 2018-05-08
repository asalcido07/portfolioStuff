<?php
    session_start();
    
    // If the user is not logged in, then redirect to home page
    if (!isset($_SESSION["username"])) {
        header('Location: ./');
        exit();
    }
    
    // If user clicked Cancel, then redirect to the view blog page
    if (isset($_POST['cancel'])) {
        header('Location: viewblog.php?u=' . $_SESSION['username']);
        exit();
    }
    
    // Send to home page if submitted data is not valid
    if (!isset($_POST['blogtext'])){
        header('Location: ./');
        exit();
    }
    
    // Assume that the Save button was clicked
    
    //Extract submitted blogtext
    $blogtext = $_POST['blogtext'];
    
    // Connect to database
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=project", "root", NULL);
    } catch (PDOExecption $e) {
        exit('Database connection failed: ' . $e->getMessage());
    }
    
    // Retrieve the actual password for given user
    $stmt = $dbh->prepare("UPDATE users SET blogtext = :blogtext WHERE username = :username"); // Sets statement for mysql, increments counter when page is viewed
    $stmt->bindParam(':blogtext', $blogtext);
    $stmt->bindParam(':username', $_SESSION["username"]);
    $stmt->execute() or exit("UPDATE failed."); // Executes $stmt

    // Redirect to othe view blog page so the user can visually confirm the changes
    header('Location: ./viewblog.php?u=' . $_SESSION['username']);
?>