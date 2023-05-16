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
	<h1>Login</h1>

	<p>Please login into your account using</p>

	<form use:form>
		<label class="label1" for="email">Email</label><br />
		<input type="email" name="email" use:validators={[required, email]} />
		<br />

		<label class="label2" for="password">Password</label><br />
		<input type="password" name="password" use:validators={[required]} />
		<br />

		<button type="button" on:click={doPost} disabled={!$form.valid}
			>Login</button
		>
	</form>
</div>