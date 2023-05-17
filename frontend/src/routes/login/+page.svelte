<script>
	import { useForm, validators, email, required } from "svelte-use-form";

	const form = useForm();

	async function doPost() {
		const { email, password } = $form;
		const data = {
			email: email?.value,
			password: password?.value,
		};

		const res = await fetch("/api/users/login", {
			method: "POST",
			mode: "no-cors",
			headers: {
				"Content-Type": "application/json",
			},
			body: JSON.stringify(data),
		});
	}
</script>

<svelte:head>
	<title>Log in</title>
	<meta name="Login page" content="Login page" />
</svelte:head>

<div class="login">
	<h1 style="color: #ff8f00">Login</h1>

	<p class="text">Please login into your account using</p>

	<form use:form>
		<input class="input1" type="email" name="email" placeholder="email:" use:validators={[required, email]} />
		<br />

		<input class="input2" type="password" name="password" placeholder="password:" use:validators={[required]} />
		<br />

		<button class="button" type="button" on:click={doPost} disabled={!$form.valid}
			>Login</button
		>
	</form>
</div>

<style>
	.login{
		background-color: #393939;
		border-radius: 20px;
		box-shadow: 15px 10px rgba(0, 0, 0, 0.3);
		margin: auto;
		text-align: center;
		padding-top: 50px;
		padding-bottom: 100px;
		width: 50%;
	}

	.text{
		background-color: #ccc;
		border-radius: 10px;;
		margin-right: 300px;
		margin-left: 300px;
	}

	.input1{
		margin-top: 10px;
		padding-right: 30px;
		padding-top: 5px;
		border-radius: 10px;
		padding-bottom: 5px;
		
	}

	.input2 {
		margin-top: 20px;
		margin-bottom: 20px;
		padding-right: 30px;
		padding-top: 5px;
		border-radius: 10px;
		padding-bottom: 5px;
		
	}

	.button {
		padding-right: 35px
		
	}
</style>