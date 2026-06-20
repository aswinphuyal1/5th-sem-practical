<?php
session_start();

/* Login */
if(isset($_POST['login']))
{
    $user = $_POST['username'];
    $pass = $_POST['password'];

    if($user == "admin" && $pass == "123")
    {
        $_SESSION['user'] = $user;
    }
}

/* Logout */
if(isset($_GET['logout']))
{
    session_destroy();
    header("Location: ".$_SERVER['PHP_SELF']);
}
?>

<!DOCTYPE html>
<html>
<body>

<?php
if(isset($_SESSION['user']))
{
    echo "<h2>Welcome ".$_SESSION['user']."</h2>";
    echo "<a href='?logout=1'>Logout</a>";
}
else
{
?>

<h2>Login Form</h2>

<form method="post">
    Username:
    <input type="text" name="username"><br><br>

    Password:
    <input type="password" name="password"><br><br>

    <input type="submit" name="login" value="Login">
</form>

<?php
}
?>

</body>
</html>