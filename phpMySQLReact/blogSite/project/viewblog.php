<?php
    // If user is not logged in, then redirect to the login page.
    session_start();
    
    /*
    if (!isset($_SESSION['username'])) {
        header('Location: ./');
    }
    */
    
    $username = $_POST['username'];
    
    console.log($username);
    
    // Get the blog text from the database for the designated user.
    // Connect to database
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=project", "root", NULL);
    } catch (PDOExecption $e) {
        exit('Database connection failed: ' . $e->getMessage());
    }
    
    // Retrieve the click count for logged in user.
    $stmt = $dbh->prepare("SELECT blogtext FROM users WHERE username = :username"); // Sets statement for mysql, increments counter when page is viewed
    $stmt->bindParam(':username', $username);
    $stmt->execute() or exit("SELECT failed."); // Executes $stmt
    
    // If there is no such user, then redirect to login page.
    if ($stmt->rowCount() == 0) {
        $response = array('result' => 'failure');
        print(json_encode($response));
        exit();
    }
   
   // Extract the blog text.
    $row = $stmt->fetch() or exit("fetch failed.");
    $blo_gtext = $row["blogtext"];
    
    $response = array('result' => 'success', 'blog_text' => $blogtext);
    print(json_encode($response));

?>