import { sveltekit } from '@sveltejs/kit/vite';
import { defineConfig } from 'vite';

const config ={
    plugins: [sveltekit()],
    server: {
        proxy: {
            '/api': {
                target: 'http://127.0.0.1:8000/',
                changeOrigin: true,
            },
            '/data': {
                target: 'http://127.0.0.1:8000/',
                changeOrigin: true,
            }
        },
    },
};


export default config;