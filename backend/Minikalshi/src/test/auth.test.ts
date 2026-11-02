import { describe, test, expect } from "bun:test";
const BACKEND_ENDPOINT = "http://localhost:3000"

describe("AUTH ENDPOINT", () => {

    const username = `user_${Date.now()}`;
    const password = "password1235"

    test("POST /api/v1/auth/signup", async () => {
        const res = await fetch(`${BACKEND_ENDPOINT}/api/v1/auth/signup`, {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify({
                username,
                password,
            })
        });
        expect(res.status).toBe(200)
    });

    test("POST /api/v1/auth/signin", async () => {
        const res = await fetch(`${BACKEND_ENDPOINT}/api/v1/auth/signin`, {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify({
                username,
                password,
            })
        });
        expect(res.status).toBe(200);

        const data = (await res.json()) as {token: string};
        expect(data.token).toBeDefined();
        console.log(data.token);
        expect(typeof data.token).toBe("string");
    });
});