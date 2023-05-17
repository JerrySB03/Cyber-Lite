<script>
  import { onMount } from "svelte";
  import { readable } from "svelte/store";

  const navItems = [
    { label: "CyberLite", href: "" },
    { label: "Home", href: "#" },
    { label: "Item 2", href: "#" },
    { label: "Úlohy", href: "/task" },
    { label: "O nás", href: "#aboutus" },
    { label: "Login", href: "/login" },
  ];
  //topbar
  let showMobileMenu = false;
  const handleMobileIconClick = () => (showMobileMenu = !showMobileMenu);
  const mediaQueryHandler = () => {
    showMobileMenu = false;
  };

  let searchTerm = "";
  let searchResults = [];
  let data = [
    { name: "Hello", des: "My word", link: "/blogpost/helloworld" },
    {
      name: "Lorem Ipsum",
      des: "Lorem ipsum dolor sit amet",
      link: "/blogpost/loremipsum",
    },
    { name: "Svelte", des: "A magical framework", link: "/blogpost/svelte" },
  ];

  onMount(async () => {
  const mediaListener = window.matchMedia("(max-width: 767px)");
  window.addEventListener("resize", handleResize);
  mediaListener.addListener(mediaQueryHandler);
  //-----------------------API--------------------
  async function fetchData() {
      const response = await fetch("/api/tasks/getall", {
        method: "GET",
        headers: {
          "Content-Type": "application/json",
        },
      });

      const jsonData = await response.json();

      // Check if the "Tasks" property exists in the response
      if (jsonData.Tasks && Array.isArray(jsonData.Tasks)) {
        // Iterate over each task in the "Tasks" array
        jsonData.Tasks.forEach((task) => {
          let searchableData = {
            name: task.name,
            des: task.description,
            link: `/task/${task.id}`,
            id: task.id,
          };

          data.push(searchableData);
        });
      }
    }

    fetchData();
  });


  function handleSearch() {
    searchResults = data.filter((item) => {
      const name = item.name.toLowerCase();
      const des = item.des.toLowerCase();
      const search = searchTerm.toLowerCase();

      return name.includes(search) || des.includes(search);
    });
  }

  //search bar resize
  let searchBarWidth = 300;
  function handleResize(event) {
    // Calculate the new width of the search bar based on the window width
    searchBarWidth = Math.min(600, window.innerWidth - 400); // Set maximum width to 600px
  }
</script>

<nav>
  <div class="inner">
    <div
      on:click={handleMobileIconClick}
      tabindex="0"
      class={`mobile-icon${showMobileMenu ? " active" : ""}`}
    >
      <div class="middle-line" />
    </div>
    <ul class={`navbar-list${showMobileMenu ? " mobile" : ""}`}>
      {#each navItems as item}
        <li>
          <a href={item.href}>{item.label}</a>
        </li>
      {/each}
    </ul>
  </div>
</nav>
<div class="search-container">
  <div class="search-bar" style="width: {searchBarWidth}px;">
    <input
      type="text"
      bind:value={searchTerm}
      placeholder="Enter your search term"
      on:input={handleSearch}
    />
    <button on:click={handleSearch}>Search</button>
  </div>
  <div class="grey-box" />

  {#if searchResults.length > 0}
    <ul class="search-results">
      {#each searchResults as result}
        <li>
          <a href={result.link}>
            <span>{result.name}</span>
            <p>{result.des}</p>
          </a>
        </li>
      {/each}
    </ul>
  {/if}
</div>

<style>
  .particles {
    position: relative;
    width: 1700px;
    height: 1000px;
  }
  .search-container {
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
    position: absolute;
    top: 200px;
    left: 50%;
    transform: translateX(-50%);
    width: calc(100% - 400px); /* Adjust the 400px value as needed */
    max-width: 600px; /* Set maximum width for the search container */
  }

  .search-bar {
    display: flex;
    align-items: center;
    justify-content: center;
    margin-bottom: 16px;
    width: 100%;
  }

  .search-bar input {
    flex-grow: 1; /* Allow the input to grow and fill the available space */
    width: 100%;
    padding: 8px;
    border: 1px solid #ccc;
    border-radius: 4px;
    margin-right: 8px;
    max-width: 100%; /* Set maximum width for the input */
  }

  .search-bar button {
    padding: 8px 16px;
    background-color: #ccc;
    color: #fff;
    border: none;
    border-radius: 4px;
    cursor: pointer;
  }

  .grey-box {
    width: 100%;
    height: 8px;
    background-color: #ccc;
  }

  .search-results {
    list-style-type: none;
    padding: 0;
    margin-top: 16px;
  }

  .search-results li {
    margin-bottom: 8px;
  }

  .search-results a {
    display: block;
    color: #333;
    text-decoration: none;
    font-weight: bold;
  }

  .search-results p {
    margin-top: 4px;
    color: #666;
  }

  nav {
    object-position: top;
    background-color: rgba(0, 0, 0, 0.8);
    font-family: "Helvetica Neue", "Helvetica", "Arial", sans-serif;
    height: 45px;
    border-radius: 15px;
    margin: auto;
    border: 2px solid #000000;
  }

  .inner {
    object-position: top;

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
