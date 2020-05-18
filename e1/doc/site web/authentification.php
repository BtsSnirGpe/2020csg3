<?php

$host="localhost";
$user="cazenave";
$password="gwadamanbima";
$db="sap_projet";

mysql_connect($host,$user,$password);
mysql_select_db($db);

if(isset($_POST['username'])){

	$uname=$_POST['username'];
	$password=$_POST['password'];
	
	$sql="select * from loginform where utilisateur='".$uname."' AND Mot_de_passe='".$password."'limit 1";
	
	$result=mysql_query($sql);
	
	if(mysql_num_rows($result)==1){
		echo "Identification Correcte !";
		exit();
	}
	else{
		echo " Mauvaise Identification !";
		exit();
	}

}

?>





<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<style>
body {
  background-color: lightblue;
}

h1 {
  color: white;
  text-align: center;
}

p {
  font-family: verdana;
  font-size: 20px;
}

		</style>
	</head>

<body>
<img src="C:\Users\famille\Desktop\damien\Projet SAP\image\logoLycee.jpg" alt="" />

	<h1>INFORMATION DES SEISMES ENREGISTREES</h1>
		<div id="container">
            <!-- zone de connexion -->
            
				<form method="POST" action="#">
					<h1>Connexion</h1>
                
					<label><b>Nom d'utilisateur :</b></label>
					<input type="text" placeholder="Entrer le nom d'utilisateur" name="username" required></br></br></br>

					<label><b>Mot de passe :</b></label>
					<input type="password" placeholder="Entrer le mot de passe" name="password" required></br></br></br>

					<input type="submit" id='submit' value='LOGIN' >
              
<!--
<?php
                if(isset($_GET['erreur'])){
                    $err = $_GET['erreur'];
                    if($err==1 || $err==2)
                        echo "<p style='color:red'>Utilisateur ou mot de passe incorrect</p>";
                }
?> -->
            </form>
        </div>


</body>
</html>
