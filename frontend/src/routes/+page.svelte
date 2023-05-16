<!-- Dark and Lightmode -->
<link rel="stylesheet" href="dark-mode.css" media="(prefers-color-scheme: dark)" />
<link rel="stylesheet" href="light-mode.css" media="(prefers-color-scheme: light), (prefers-color-scheme: no-preference)" />

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
	const mediaQueryHandler=() => {
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
</style>