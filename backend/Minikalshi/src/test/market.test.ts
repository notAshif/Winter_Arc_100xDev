import { describe, test, expect, beforeAll } from "bun:test";

const BACKEND_ENDPOINT = "http://localhost:3000";

describe("MARKET ENDPOINT", () => {
    let marketId = "";

    test("POST /api/v1/market - create market with yes/no order book", async () => {

        const username = `user_${Date.now()}`;
        const password = "password1235";

        await fetch(`${BACKEND_ENDPOINT}/api/v1/auth/signup`, {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify({ username, password }),
        })

        const signin = await fetch(`${BACKEND_ENDPOINT}/api/v1/auth/signin`, {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify({ username, password }),
        });

        const authData = (await signin.json()) as { token: string };
        const token = authData.token;

        const res = await fetch(`${BACKEND_ENDPOINT}/api/v1/market`, {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
                "Authorization": `Bearer ${token}`,
            },
            body: JSON.stringify({ title: "WIll you be my gf?" }),
        });

        expect(res.status).toBe(201);
        const data = (await res.json()) as { market: { id: string; totalIssued: number } };
        console.log(data.market.id)
        expect(data.market.id).toBeDefined();
        expect(data.market.totalIssued).toBe(0);

        marketId = data.market.id;
    })

    test("GET /api/v1/market - public market listk", async () => {
    
        const res = await fetch(`${BACKEND_ENDPOINT}/api/v1/market`);

        const data = await res.json()
        expect(res.status).toBe(200);
        expect(Array.isArray(data)).toBe(true);
    })
})
