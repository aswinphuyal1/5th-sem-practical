<!DOCTYPE html>
<html>
<body>

<h2>GET Form</h2>
<form method="get">
    <input type="text" name="gname" placeholder="Enter Name">
    <input type="submit" value="GET Submit">
</form>

<?php
if(isset($_GET['gname']))
{
    echo "GET Name: " . $_GET['gname'] . "<br>";
}
?>

<h2>POST Form</h2>
<form method="post">
    <input type="text" name="pname" placeholder="Enter Name">
    <input type="submit" value="POST Submit">
</form>

<?php
if(isset($_POST['pname']))
{
    echo "POST Name: " . $_POST['pname'];
}
?>

</body>
</html>