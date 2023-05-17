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

<div
  class="background"
  style="background-image: url('file:///home/jumanji/Documents/Code/Cyber-Lite/frontend/static/Hory.jpg');"
>
  <nav>
    <a href="/">
      <svg
        version="1.2"
        xmlns="http://www.w3.org/2000/svg"
        viewBox="0 0 750 300"
        width="75"
        height="30"
        style="float: left; border-radius: 8px; margin-top: 8px; margin-left: 12px; cursor: pointer;"
      >
        <style>
          .s0 {
            fill: #6e6258;
            stroke: #000000;
            stroke-width: 2;
          }
          .s1 {
            fill: #000000;
          }
          .s2 {
            fill: #000000;
            stroke: #000000;
            stroke-width: 2;
          }
          .s3 {
            fill: none;
            stroke: #000000;
            stroke-width: 2;
          }
          .s4 {
            fill: #ffffff;
            stroke: #000000;
            stroke-width: 2;
          }
        </style>
        <path
          id="Tvar 1"
          class="s0"
          d="m70 291c0 0 15.8-35.3 20-53 4.2-17.7 10.5-35 4-51-6.5-16-19-43.6-22-55-3-11.4-26.1-35.7-28-49-1.9-13.3-2-17-2-17 0 0 6.8 1 13 4 6.2 3 29.1 10 35 11 5.9 1 31.7-2.3 42-11 10.3-8.7 15.3-11.6 19-18 3.7-6.4 6-16 6-16 0 0 8.4-27.9 12-31 3.6-3.1 4.7-10 12 1 7.3 11 17 45 17 45 0 0 3.7 15.6 9 18 5.3 2.4 9.5 5.6 13 9 3.5 3.4 8.4 7.3 11 16 2.6 8.7 7.5 27.8 7 32-0.5 4.2 3 10 3 10l8 5 4 12c0 0 2.4 3.4 17 11 14.6 7.6 11.4 8.6 20 12 8.6 3.4 10.7 16 20 3 9.3-13 21.6-28 23-33 1.4-5 7.5-11.2 7-18-0.5-6.8-1-10-1-10 0 0 0-7.5 5-10 5-2.5 8-1 8-1 0 0-4-20.7 9-22 13-1.3 15.5-9.6 25-8 9.5 1.6 16.8 4 19 9 2.2 5 6 19 6 19 0 0 12 18 3 21-9 3-17 6-17 6l-12 26-7 10c0 0-1.8 26.3-7 34-5.2 7.7-30.5 60.5-40 66-9.5 5.5-8.8 8-15 9-6.2 1-19 14-19 14z"
        />
        <path id="Tvar 9" class="s0" d="m303 200" />
        <path
          id="Cyber-Lite"
          class="s1"
          aria-label="Cyber-Lite"
          d="m180.4 243.3l1.3 10.3q-3.3 1.6-7.3 2.6-4.1 0.9-9.9 0.9-5 0-9.3-1.6-4.1-1.7-7.1-4.8-2.9-3-4.5-7.4-1.6-4.5-1.6-10 0-6.3 2.2-12.5 2.2-6.3 6.5-11.1 4.4-5 10.6-8.1 6.3-3 14.5-3 3.9 0 7.6 0.9 3.8 0.9 8 3.1l-4.6 9.8q-3.4-1.8-6-2.4-2.7-0.7-5.8-0.7-4.6 0-8.3 1.9-3.7 1.9-6.4 5.1-2.5 3.2-3.9 7.4-1.4 4.2-1.4 8.9 0 7.1 3.1 10.4 3.1 3.2 9 3.2 3.9 0 7.1-0.8 3.3-0.8 6.2-2.1zm40.9-29.9h12.8q-2.3 6.1-4.7 11.5-2.2 5.3-4.7 10.2-2.5 4.8-5.2 9.2-2.7 4.3-5.7 8.6-2.2 3.2-4.5 6.4-2.4 3.3-5.3 5.9-2.8 2.5-6.4 4.2-3.5 1.6-8.1 1.6-2.8 0-4.8-0.5-2.1-0.6-3.9-1.5l3.7-9.4q1.6 0.6 2.9 1 1.3 0.3 3.2 0.3 2.8 0 5.3-1.7 2.6-1.9 4.3-5-2.1-8.1-3.9-18.1-1.7-10.1-2.3-22.7h12.4q0 3.2 0.3 7 0.2 3.8 0.5 7.7 0.4 3.8 0.8 7.4 0.4 3.7 0.9 6.6 3.9-5.9 6.8-13 3-7.1 5.6-15.7zm38.6-0.9q3.9 0 6.7 1.4 2.9 1.4 4.7 3.7 1.9 2.4 2.8 5.5 0.9 3.2 0.9 6.8 0 5.6-2.1 10.6-2.1 5-5.6 8.7-3.6 3.6-8.5 5.8-4.8 2.1-10.5 2.1-0.7 0-2.6 0-1.8 0-4.1-0.4-2.4-0.3-5-0.9-2.6-0.7-5-1.8l14-58.9 12.6-2-5 20.9q1.6-0.7 3.2-1.1 1.6-0.4 3.5-0.4zm-10.5 34.7q2.8 0 5.3-1.4 2.5-1.4 4.3-3.7 1.9-2.3 2.9-5.2 1.1-2.9 1.1-6.1 0-3.9-1.3-6.1-1.3-2.2-4.8-2.2-1.1 0-3 0.5-1.8 0.4-3.2 1.7l-5.4 22.1q0.5 0.1 0.8 0.2 0.4 0.1 0.8 0.2 0.4 0 1 0 0.6 0 1.5 0zm31.2-7.9q0-5.2 1.8-10 1.9-4.9 5.2-8.6 3.3-3.8 8-6.1 4.8-2.3 10.6-2.3 2.8 0 5.2 0.8 2.4 0.8 4.2 2.3 1.9 1.6 2.9 3.8 1 2.2 1 5 0 4.6-2 7.7-2 3.2-5.7 5.2-3.5 2-8.5 2.9-4.9 0.9-10.8 0.9 0.6 3.4 2.5 4.8 1.9 1.4 6 1.4 2.6 0 5.3-0.4 2.7-0.5 5-1.4l0.9 9.5q-2.2 0.9-5.8 1.6-3.5 0.7-7.6 0.7-5 0-8.5-1.3-3.4-1.5-5.6-3.9-2.1-2.5-3.1-5.7-1-3.2-1-6.9zm23.6-17.5q-4.1 0-7.3 3-3.1 2.9-4 7.8 5-0.2 8.1-0.8 3-0.7 4.7-1.7 1.7-1 2.3-2.1 0.6-1.2 0.6-2.3 0-3.9-4.4-3.9zm53.1-7.8l-3.6 9.8q-1.6-0.4-3.2-0.8-1.6-0.4-4.7-0.4-1.1 0-2.5 0.3-1.3 0.1-2.2 0.4l-7.9 32.7h-12.1l9.8-40.3q3.4-1.2 7.7-2.1 4.4-1.1 9.8-1.1 2.1 0 4.5 0.4 2.5 0.3 4.4 1.1zm-1.4 23.3l2.7-10.9h23.4l-2.6 10.9zm43.1 8h24.8l-2.6 10.7h-37.4l13.5-56.1h12.6zm52.3-31.9l-10.2 42.6h-12l10.2-42.6zm-4.4-5.2q-2.5 0-4.6-1.5-2-1.5-2-4.6 0-1.7 0.7-3.2 0.7-1.5 1.8-2.6 1.2-1.1 2.6-1.7 1.6-0.7 3.3-0.7 2.5 0 4.5 1.6 2 1.4 2 4.5 0 1.7-0.7 3.2-0.6 1.5-1.8 2.6-1.1 1.1-2.7 1.7-1.4 0.7-3.1 0.7zm8.7 28.1l8-33.6 12.5-1.9-3.1 12.6h13.5l-2.4 9.8h-13.4l-3.6 14.9q-0.5 1.9-0.6 3.5-0.1 1.6 0.4 2.9 0.6 1.1 1.9 1.7 1.3 0.7 3.5 0.7 2 0 3.7-0.3 1.9-0.4 3.8-1.1l0.9 9.2q-2.5 0.9-5.3 1.6-2.8 0.6-6.7 0.6-5.6 0-8.7-1.6-3.1-1.7-4.4-4.5-1.3-2.9-1.1-6.7 0.2-3.7 1.1-7.8zm31.3 3q0-5.2 1.8-10.1 1.8-4.8 5.2-8.6 3.3-3.8 8-6 4.8-2.4 10.5-2.4 2.8 0 5.3 0.8 2.4 0.8 4.2 2.4 1.9 1.5 2.8 3.8 1.1 2.2 1.1 5 0 4.5-2 7.7-2.1 3.2-5.7 5.2-3.6 1.9-8.5 2.8-5 0.9-10.8 0.9 0.6 3.4 2.4 4.9 2 1.3 6.1 1.3 2.6 0 5.3-0.4 2.6-0.4 5-1.3l0.9 9.4q-2.3 0.9-5.8 1.7-3.5 0.7-7.7 0.7-5 0-8.5-1.4-3.4-1.4-5.6-3.9-2.1-2.4-3-5.6-1-3.3-1-6.9zm23.6-17.5q-4.2 0-7.3 3-3.1 2.9-4.1 7.7 5.1-0.1 8.1-0.8 3.1-0.7 4.8-1.7 1.7-0.9 2.3-2.1 0.5-1.1 0.5-2.2 0-3.9-4.3-3.9z"
        />
        <path
          id="Vrstva 3"
          class="s2"
          d="m377.9 100.6c-2.4-0.6-3.5-4.4-2.6-8.6 1-4.2 3.7-7.2 6.1-6.6 2.4 0.5 3.6 4.4 2.6 8.6-0.9 4.2-3.7 7.1-6.1 6.6z"
        />
        <path
          id="Tvar 10"
          class="s2"
          d="m368.5 123c-3.6 0-6.5-5.4-6.5-12 0-6.6 2.9-12 6.5-12 3.6 0 6.5 5.4 6.5 12 0 6.6-2.9 12-6.5 12z"
        />
        <path
          id="Tvar 11"
          class="s2"
          d="m384.9 131.3c-3.4-2-3.3-8.2 0.1-13.9 3.4-5.7 8.8-8.7 12.1-6.7 3.4 2 3.3 8.2-0.1 13.9-3.4 5.7-8.8 8.7-12.1 6.7z"
        />
        <path
          id="Tvar 8"
          class="s2"
          d="m391.9 103.9c-2.4-0.6-3.5-4.4-2.6-8.6 1-4.2 3.7-7.2 6.1-6.6 2.4 0.5 3.6 4.4 2.6 8.6-0.9 4.2-3.7 7.1-6.1 6.6z"
        />
        <path
          id="Tvar 2"
          class="s3"
          d="m157 138.1c-5.1 0.1-23.6 6.9-41.2 21-20.6 16.4-32.1 37.1-33.4 42.3"
        />
        <path
          id="Tvar 4"
          class="s3"
          d="m166.2 137.7c-5.3-0.5-27 2.9-50.1 14-24.4 11.7-41.5 27.7-44.5 32.3"
        />
        <path
          id="Tvar 3"
          class="s3"
          d="m155.7 138.7c-4.4 1.8-21.5 13.7-36.3 32.7-13 16.8-19.9 33.4-20.6 37.8"
        />
        <path
          id="Tvar 7"
          class="s3"
          d="m182.6 128c2.7-0.8 15.2-1.8 30.2-1.1 24.4 1.2 44.9 6.5 48.5 7.8"
        />
        <path
          id="Tvar 5"
          class="s3"
          d="m176.3 130.6c3.6-3 20.7-12.9 43.2-21 24.9-8.9 46.9-12 51.8-12"
        />
        <path
          id="Tvar 6"
          class="s3"
          d="m179.1 128.9c4-1.8 23.4-7.9 47.5-10.7 20.6-2.4 37.7-1.8 41.8-1"
        />
        <path
          id="Vrstva 2"
          class="s2"
          d="m164.3 131.7c-5.1 3.3-9.4 10-7.6 11.4 1.5 1.1 5.1-3.5 10.1-3.3 4.3 0.1 6.3 4.7 8.5 3 1.9-1.4-1.1-4.9 0.7-7.6 2.6-3.8 9.6-2.4 10.5-3.4 1.7-2.1-14-5.4-22.2-0.1z"
        />
        <path
          id="Tvar 12"
          class="s2"
          d="m129.8 131.5c-4.2 2.1-10.8-2.7-14.9-10.8-4.1-8-4-16.3 0.2-18.4 4.2-2.1 10.8 2.8 14.9 10.8 4.1 8.1 4 16.3-0.2 18.4z"
        />
        <path
          id="Tvar 13"
          class="s2"
          d="m182.7 107.3c-3.9 1.6-9.5-3.3-12.6-11-3.2-7.7-2.6-15.1 1.2-16.7 3.9-1.6 9.5 3.3 12.6 11 3.2 7.7 2.6 15.2-1.2 16.7z"
        />
        <path
          id="Tvar 14"
          class="s4"
          d="m127 130c-2.2 0-4-2.7-4-6 0-3.3 1.8-6 4-6 2.2 0 4 2.7 4 6 0 3.3-1.8 6-4 6z"
        />
        <path
          id="Tvar 15"
          class="s4"
          d="m181 106c-1.7 0-3-2-3-4.5 0-2.5 1.3-4.5 3-4.5 1.7 0 3 2 3 4.5 0 2.5-1.3 4.5-3 4.5z"
        />
      </svg>
    </a>
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
</div>

<style>
  .background {
    height: 1400px;
  }

  .particles {
    position: relative;
    width: 1700px;
    height: 1000px;
  }
  .search-container {
    background-color: #424245;
    border-radius: 20px;
    padding-left: 30px;
    padding-top: 15px;
    padding-right: 30px;
    box-shadow: 15px 10px rgba(0, 0, 0, 0.3);
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
    background-color: #393939;
    padding-left: 100px;
    padding-right: 100px;
    border-radius: 20px;
    padding-top: 7px;
    padding-bottom: 7px;
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
    border-radius: 10px;
    margin-bottom: 10px;
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
    color: #ffffff;
    text-decoration: none;
    font-weight: bold;
  }

  .search-results p {
    margin-top: 4px;
    color: #ffffff;
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
