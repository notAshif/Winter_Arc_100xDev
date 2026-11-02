import { describe, test, expect } from "bun:test";

const BACKEND_ENDPOINT = "http://localhost:3000";

describe("CREATE ORDER ENDPOINT", () => {
    test("POST /api/v1/createOrder", async () => {

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

        await fetch(`${BACKEND_ENDPOINT}/api/v1/auth/onramp`, {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
                "Authorization": `Bearer ${token}`,
            },
            body: JSON.stringify({ amount: 1000 }),
        });

        const marketRes = await fetch(`${BACKEND_ENDPOINT}/api/v1/market`, {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
                "Authorization": `Bearer ${token}`,
            },
            body: JSON.stringify({ title: "WIll you be my gf?" }),
        });

        const marketData = (await marketRes.json()) as { market: {id: string} };
        const marketId = marketData.market.id;

        const createOrderRes = await fetch(`${BACKEND_ENDPOINT}/api/v1/createOrder`, {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
                "Authorization": `Bearer ${token}`,
            },
            body: JSON.stringify({
                marketId,
                type: "buy",
                side: "YES",
                price: 80,
                qty: 7,
            }),
        });

        expect(createOrderRes.status).toBe(201);
        const data = (await createOrderRes.json()) as {
            status: string;
            filledQty: number;
            remainingQty: number;
        };
        expect(data.status).toBe("OPEN"); 
        expect(data.filledQty).toBe(0);
        expect(data.remainingQty).toBe(7);
    })
})