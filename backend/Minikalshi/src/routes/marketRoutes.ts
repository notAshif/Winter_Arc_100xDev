import { Router } from "express";
import { marketController } from "../controllers/marketController";
import { OrderController } from "../controllers/orderController";
import { auth } from "../middleware/auth";

const router = Router();

router.post("/", auth, marketController.create);
router.get("/", marketController.getMarkets);
router.get("/:marketId/orderbook", OrderController.getOrderbook);

export default router;
