import { Router } from "express";
import { OrderController } from "../controllers/orderController";
import { auth } from "../middleware/auth";

const router = Router();

router.post("/", auth, OrderController.create);
router.get("/:marketId", OrderController.getOrderbook);

export default router;
