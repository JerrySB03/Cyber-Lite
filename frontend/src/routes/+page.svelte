<!-- Dark and Lightmode -->
<link rel="stylesheet" href="dark-mode.css" media="(prefers-color-scheme: dark)" />
<link rel="stylesheet" href="light-mode.css" media="(prefers-color-scheme: light), (prefers-color-scheme: no-preference)" />
<link rel="stylesheet" type="text/css" href="http://fonts.googleapis.com/css?family=Ubuntu:regular,bold&subset=Latin">

<script>
	import { readable } from 'svelte/store';



	import { onMount } from "svelte";

	// Show mobile icon and display menu
	let showMobileMenu = false;

	// List of navigation items
	const navItems = [
	{ label: "CyberLite", href: "#" },
	{ label: "Home", href: "#" },
	{ label: "Item 2", href: "#" },
	{ label: "Item 3", href: "#" },
	{ label: "O nás", href: "/aboutus" },
	{ label: "Login", href: "/login" },
	];

	const handleMobileIconClick = () => (showMobileMenu = !showMobileMenu);
	const mediaQueryHandler= ()  => {
		showMobileMenu = false;

	};
	onMount(() => {
	const mediaListener = window.matchMedia("(max-width: 767px)");

	mediaListener.addListener(mediaQueryHandler);
	});

	
</script>



<nav>
	<div class="inner">
	  <div on:click={handleMobileIconClick} tabindex="0" class={`mobile-icon${showMobileMenu ? ' active' : ''}`}>
		<div class="middle-line"></div>
	  </div>
	  <ul class={`navbar-list${showMobileMenu ? ' mobile' : ''}`}>
		{#each navItems as item}
		  <li>
			<a href={item.href}>{item.label}</a>
		  </li>
		{/each}
	  </ul>
	</div>
	<div class="wallground"></div>
	<p style="border-radius: 20px; border-width:3px; border-style:solid; border-color:#7C7C7C; padding: 0em; margin-left: 50px; margin-right: 350px" class="line"></p>
	<div class="changeText">
		<p></p>
	</div>
	<div class="div-topText">
		<p style="border-radius: 20px; border-width:3px; border-style:solid; border-color: #7C7C7C; padding: 0em; " class="line"></p>
		<h1 class="h1-mt; font-family: Ubuntu">Lorem ipsum</h1>
		<p style="font-family: Ubuntu">Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Fusce suscipit libero eget elit. Sed vel lectus. Donec odio tempus molestie, porttitor ut, iaculis quis, 
			sem. Integer rutrum, orci vestibulum ullamcorper ultricies, lacus quam ultricies odio, vitae placerat pede sem sit amet enim. Aliquam erat volutpat. Cras pede 
			libero, dapibus nec, pretium sit amet, tempor quis. Etiam bibendum elit eget erat. Duis condimentum augue id magna semper rutrum. In dapibus augue non sapien. 
			Sed ac dolor sit amet purus malesuada congue. Maecenas fermentum, sem in pharetra.</p>
	</div>
	<div class="div-newChall">
		<div class="bar">
			<div class="redButton" style = "font-family: Ubuntu; position:relative; left:4px; top:15px; text-align: center"></div>
			<div class="yellowButton" style = "font-family: Ubuntu; position:relative; left:2px; top:0px;"></div>
			<div class="greenButton" style = "font-family: Ubuntu; position:relative; left:0px; top:-15px;"></div>
			<div class="searchBar" style = "font-family: Ubuntu; position:relative; left:350px; top: -35px; border-radius: 20px; text-align: center; font-size: 14px">Nove ulohy</div>
		</div>
		<p>Jak předejít phishingu, rozdíl mezi phishingem a whalingem</p>
	</div>
	<div class="shadow"></div>
	<div class="div-bottomText" style="font-family: U;">
		<h2 style="text-decoration: underline;">Lorem susum</h2>
		<p>Aenean fermentum risus id tortor. Integer malesuada. Nullam dapibus fermentum ipsum. Quisque porta. Morbi scelerisque luctus velit. Fusce tellus odio, dapibus id 
			fermentum quis, suscipit id erat. In dapibus augue non sapien. Vivamus luctus egestas leo. Integer in sapien. Vivamus luctus egestas leo. Nullam faucibus mi quis 
			velit. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet ut et voluptates repudiandae sint et </p>
	</div>
	<p style="border-radius: 20px; border-width:3px; border-style:solid; border-color:#7C7C7C; padding: 0em; margin-left: 50px; margin-right: 350px" class="line"></p>
  </nav>


<style>
	nav {
    background-color: rgba(0, 0, 0, 0.8);
    font-family: "Helvetica Neue", "Helvetica", "Arial", sans-serif;
    height: 45px;
	border-radius: 15px;
  	margin: auto;
 	 border: 2px solid #000000;
  }

  .inner {
  max-width: 980px;
  padding-left: 20px;
  padding-right: 20px;
  margin: auto;

  padding: 20px; 
  box-sizing: border-box;
  display: flex;
  align-items: center;
  height: 100%;
}

  .mobile-icon {
    width: 25px;
    height: 14px;
    position: relative;
    cursor: pointer;
  }

  .mobile-icon:after,
  .mobile-icon:before,
  .middle-line {
    content: "";
    position: absolute;
    width: 100%;
    height: 2px;
    background-color: #fff;
    transition: all 0.4s;
    transform-origin: center;
  }

  .mobile-icon:before,
  .middle-line {
    top: 0;
  }

  .mobile-icon:after,
  .middle-line {
    bottom: 0;
  }

  .mobile-icon:before {
    width: 66%;
  }

  .mobile-icon:after {
    width: 33%;
  }

  .middle-line {
    margin: auto;
  }

  .mobile-icon:hover:before,
  .mobile-icon:hover:after,
  .mobile-icon.active:before,
  .mobile-icon.active:after,
  .mobile-icon.active .middle-line {
    width: 100%;
  }

  .mobile-icon.active:before,
  .mobile-icon.active:after {
    top: 50%;
    transform: rotate(-45deg);
  }

  .mobile-icon.active .middle-line {
    transform: rotate(45deg);
  }

  .navbar-list {
    display: none;
    width: 100%;
    justify-content: space-between;
    margin: 0;
    padding: 0 40px;
  }

  .navbar-list.mobile {
    background-color: rgba(0, 0, 0, 0.8);
    position: fixed;
    display: block;
    height: calc(100% - 45px);
    bottom: 0;
    left: 0;
  }

  .navbar-list li {
    list-style-type: none;
    position: relative;
  }

  .navbar-list li:before {
    content: "";
    position: absolute;
    bottom: 0;
    left: 0;
    width: 100%;
    height: 1px;
    background-color: #424245;
  }

  .navbar-list a {
    color: #fff;
    text-decoration: none;
    display: flex;
    height: 45px;
    align-items: center;
    padding: 0 10px;
    font-size: 13px;
  }

  @media only screen and (min-width: 767px) {
    .mobile-icon {
      display: none;
    }

    .navbar-list {
      display: flex;
      padding: 0;
    }

    .navbar-list a {
      display: inline-flex;
    }
  }

  .wallground{
	background-color: #606064;
	height: 2000;
	width: 900;
  }

  .div-topText{
	
	
	color: #fff;
	padding-right: 350px;
	padding-left: 50px;
	padding-top: 70px;
	
	

  }
  h1{
	text-decoration: underline;
  }

  .div-newChall{
	border-radius: 20px;
	background-color: #535363;
	width: 800px;
	height: 500px;
	padding-top: 20px;
	padding-left: 20px;
	margin-left: 50px;
	margin-top: 90px;
	
  }
  .bar{
	border-radius: 30px;
	background-color: #424245;
	width: 780px;
	height: 40px;

  }

  .redButton{
	background-color: rgb(255, 0, 0);
	width: 15px;
	height: 15px;
	border-radius: 30px;
	margin-left: 750px;
	
	
  }
  .yellowButton{
	background-color: rgb(251, 255, 0);
	width: 15px;
	height: 15px;
	border-radius: 30px;
	margin-left: 730px;
	
  }
  .greenButton{
	background-color: rgb(0, 255, 0);
	width: 15px;
	height: 15px;
	border-radius: 30px;
	margin-left: 710px;

  }
  .searchBar{
	background-color: #39393b;
	width: 100px;
	height: 20px;
	
  }

  .div-bottomText{
	
	
	color: #fff;
	padding-right: 350px;
	padding-left: 50px;
	padding-top: 90px;
  }
</style>
