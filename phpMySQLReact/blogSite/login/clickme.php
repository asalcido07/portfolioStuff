<?php
    // If user is not logged in, then redirect to the login page.
    session_start();
    if (!isset($_SESSION['username'])) {
        header('Location: ./');
    }
    
    // Get the click count from the database for the logged in user.
    // Connect to database
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=login", "root", NULL);
    } catch (PDOExecption $e) {
        exit('Database connection failed: ' . $e->getMessage());
    }
    
    // Retrieve the click count for logged in user.
    $stmt = $dbh->prepare("SELECT click_count FROM users WHERE username = :username"); // Sets statement for mysql, increments counter when page is viewed
    $stmt->bindParam(':username', $_SESSION['username']);
    $stmt->execute() or exit("SELECT failed."); // Executes $stmt
    
    // If there is no such user, then redirect to login page.
    if ($stmt->rowCount() == 0) {
        header('Location: ./');
        exit();
    }
   
   // Extract the click count.
    $row = $stmt->fetch() or exit("fetch failed.");
    $click_count = $row["click_count"];
    
?>

<h1>Clickme Page</h1>

<form action="logout.php" method="post">
        <input type="submit" value="logout" />
</form>

<p id="counter"><?php print($click_count) ?></p>

<button id="button">Click Me!</button>

<div id="error_message"></div>

<script>
    function record_click(count) {
    var httpRequest = new XMLHttpRequest();
    if (!httpRequest) {
        alert('Browser not supported.');
        return;
    }
    httpRequest.onreadystatechange = function() {
        if (httpRequest.readyState === XMLHttpRequest.DONE) {
            if (httpRequest.status === 200) {
                    if (httpRequest.responseText.length > 0) {
                        document.getElementById('error_message').innerHTML = httpRequest.responseText;   
                }
            } else {
                alert('There was a problem with the request.');
                return;
            }
        }
    };
    httpRequest.open('POST', 'https://cse405-adam-salcido.c9users.io/login/record_click.php');
    httpRequest.send(count);
}

(function() {
    var count = <?php print($click_count) ?>;
    var counter = document.getElementById('counter');
    var button = document.getElementById('button');
    button.onclick = function() {
        counter.innerHTML = ++count;
        record_click(count);
    }

})();
</script>