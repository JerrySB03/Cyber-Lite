import { json } from '@sveltejs/kit';
const prerender = true;
/** @type {import('./$types').RequestHandler} */
export function GET(event) {
    // log all headers
    return json({
        fetch: event.fetch('/api/tasks/' + event.params.taskId, {
            method: 'GET',
            mode: 'no-cors',
        }),
        cookies: event.request.headers.get('Cookie')
    });
}