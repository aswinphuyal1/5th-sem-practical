<!DOCTYPE html>
<html>
<body>

<?php

$conn = mysqli_connect("localhost", "root", "");

if (!$conn) {
    die("Connection Failed");
}

$sql = "CREATE DATABASE mydb";

if (mysqli_query($conn, $sql)) {
    echo "Database Created Successfully";
} else {
    echo "Error Creating Database";
}

mysqli_close($conn);

?>

</body>
</html>