<?php
$conn = mysqli_connect("localhost", "root", "", "mydb");

/* CREATE */
if(isset($_POST['save'])){
    $name = $_POST['name'];
    mysqli_query($conn, "INSERT INTO student(name) VALUES('$name')");
}

/* DELETE */
if(isset($_GET['delete'])){
    $id = $_GET['delete'];
    mysqli_query($conn, "DELETE FROM student WHERE id=$id");
}

/* UPDATE */
if(isset($_POST['update'])){
    $id = $_POST['id'];
    $name = $_POST['name'];
    mysqli_query($conn, "UPDATE student SET name='$name' WHERE id=$id");
}

/* FETCH DATA FOR EDIT */
$edit = null;
if(isset($_GET['edit'])){
    $id = $_GET['edit'];
    $edit = mysqli_fetch_assoc(
        mysqli_query($conn, "SELECT * FROM student WHERE id=$id")
    );
}
?>

<!DOCTYPE html>
<html>
<body>

<h2>CRUD System</h2>

<form method="post">
    <input type="hidden" name="id"
           value="<?php echo $edit['id'] ?? ''; ?>">

    Name:
    <input type="text" name="name"
           value="<?php echo $edit['name'] ?? ''; ?>">

    <?php if($edit){ ?>
        <input type="submit" name="update" value="Update">
    <?php } else { ?>
        <input type="submit" name="save" value="Save">
    <?php } ?>
</form>

<hr>

<?php
$result = mysqli_query($conn, "SELECT * FROM student");

while($row = mysqli_fetch_assoc($result)){
    echo $row['id']." - ".$row['name'];
    echo " <a href='?edit=".$row['id']."'>Edit</a>";
    echo " <a href='?delete=".$row['id']."'>Delete</a><br>";
}
?>

</body>
</html>