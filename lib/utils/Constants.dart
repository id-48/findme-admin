import 'package:firebase_core/firebase_core.dart';

const mAppName = 'Find Me';

const currencySymbolDefault = '₹';
const currencyCodeDefault = 'INR';

/// Don't add slash at the end of the url
const DOMAIN_URL = '';
const mBaseUrl = "https://dcb2324-node-deploy-b1891009c4ea.herokuapp.com/";

const mOneSignalAppId = '';
const mOneSignalRestKey = '';
const mOneSignalChannelId = '';

FirebaseOptions firebaseOptions = FirebaseOptions(
    apiKey: "AIzaSyAZXwFcV8WKpsMwyWTqPxFCIcuVbHBEAnk",
    authDomain: "find-me-df9be.firebaseapp.com",
    projectId: "find-me-df9be",
    storageBucket: "find-me-df9be.appspot.com",
    messagingSenderId: "314390146541",
    appId: "1:314390146541:web:787dbdb81749358d120be4",
    measurementId: "G-3LG5HR1VFK");

const authToken =
    "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IjY2MmYyY2MwZjA4ODkxM2E5ZDg4YmQ0YiIsImlhdCI6MTcxNDQ1NzM2M30.8RFPJ3EK6WkLD-8XaojlJ9vfxyox4zNvAWecikdzSMI";
const defaultPhoneCode = '+91';
const defaultCurrencySymbol = '₹';
const defaultCurrencyCode = 'INR';

const minContactLength = 10;
const maxContactLength = 14;
const digitAfterDecimal = 2;
const pinCodeLength = 6;

const MESSAGES_COLLECTION = "messages";
const USER_COLLECTION = "users";
const CONTACT_COLLECTION = "contact";
const CHAT_DATA_IMAGES = "chatImages";

const CLIENT = 'client';
const ADMIN = 'admin';
const DELIVERYMAN = 'delivery_man';
const DEMO_ADMIN = 'demo_admin';

const textPrimarySizeGlobal = 16.00;
const textBoldSizeGlobal = 16.00;
const textSecondarySizeGlobal = 14.00;
const borderRadius = 16.00;

double tabletBreakpointGlobal = 600.0;
double desktopBreakpointGlobal = 720.0;
double statisticsItemWidth = 230.0;

const RESTORE = 'restore';
const FORCE_DELETE = 'forcedelete';
const DELETE_USER = 'deleted_at';

const CHARGE_TYPE_FIXED = 'fixed';
const CHARGE_TYPE_PERCENTAGE = 'percentage';

const DISTANCE_UNIT_KM = 'km';
const DISTANCE_UNIT_MILE = 'mile';

const PAYMENT_TYPE_STRIPE = 'stripe';
const PAYMENT_TYPE_RAZORPAY = 'razorpay';
const PAYMENT_TYPE_PAYSTACK = 'paystack';
const PAYMENT_TYPE_FLUTTERWAVE = 'flutterwave';
const PAYMENT_TYPE_PAYPAL = 'paypal';
const PAYMENT_TYPE_PAYTABS = 'paytabs';
const PAYMENT_TYPE_MERCADOPAGO = 'mercadopago';
const PAYMENT_TYPE_PAYTM = 'paytm';
const PAYMENT_TYPE_MYFATOORAH = 'myfatoorah';
const PAYMENT_TYPE_CASH = 'cash';
const PAYMENT_TYPE_WALLET = 'wallet';
const PAYMENT_GATEWAY_LIST = 'PAYMENT_GATEWAY_LIST';

// OrderStatus
const ORDER_CREATED = 'create';
const ORDER_ACCEPTED = 'active';
const ORDER_CANCELLED = 'cancelled';
const ORDER_DELAYED = 'delayed';
const ORDER_ASSIGNED = 'courier_assigned';
const ORDER_ARRIVED = 'courier_arrived';
const ORDER_PICKED_UP = 'courier_picked_up';
const ORDER_DELIVERED = 'completed';
const ORDER_DRAFT = 'draft';
const ORDER_DEPARTED = 'courier_departed';
const ORDER_TRANSFER = 'courier_transfer';
const ORDER_PAYMENT = 'payment_status_message';
const ORDER_FAIL = 'failed';

const DECLINE = 'decline';
const REQUESTED = 'requested';
const APPROVED = 'approved';

const DIALOG_TYPE_DELETE = 'Delete';
const DIALOG_TYPE_RESTORE = 'Restore';
const DIALOG_TYPE_ENABLE = 'Enable';
const DIALOG_TYPE_DISABLE = 'Disable';

const TOKEN = 'TOKEN';
const USER_ID = 'USER_ID';
const USER_TYPE = 'USER_TYPE';
const USER_EMAIL = 'USER_EMAIL';
const USER_PASSWORD = 'USER_PASSWORD';
const NAME = 'NAME';
const USER_PROFILE_PHOTO = 'USER_PROFILE_PHOTO';
const USER_CONTACT_NUMBER = 'USER_CONTACT_NUMBER';
const USER_NAME = 'USER_NAME';
const USER_ADDRESS = 'USER_ADDRESS';
const IS_LOGGED_IN = 'IS_LOGGED_IN';
const IS_ADMIN_LOGGED_IN = 'IS_ADMIN_LOGGED_IN';
const USER_ROLE = 'USER_ROLE';
const USER_FIRST_ROLE = 'USER_FIRST_ROLE';
const FCM_TOKEN = 'FCM_TOKEN';
const USER_STATUS = 'USER_STATUS';
const USER_PLAYER_ID = 'USER_PLAYER_ID';
const FILTER_DATA = 'FILTER_DATA';
const UID = 'UID';
const IS_VERIFIED_DELIVERY_MAN = 'IS_VERIFIED_DELIVERY_MAN';
const RECENT_ADDRESS_LIST = 'RECENT_ADDRESS_LIST';
const REMEMBER_ME = 'REMEMBER_ME';
const OTP_VERIFIED = "OTP_VERIFIED";

const COUNTRY_ID = 'COUNTRY_ID';
const COUNTRY_DATA = 'COUNTRY_DATA';

const CITY_ID = 'City';
const CITY_DATA = 'CITY_DATA';

const PAYMENT_ON_PICKUP = 'on_pickup';
const PAYMENT_ON_DELIVERY = 'on_delivery';

// Vehicle status
const VEHICLE_IMAGE = 'VEHICLE_IMAGE';

// Payment status
const PAYMENT_PENDING = 'pending';
const PAYMENT_FAILED = 'failed';
const PAYMENT_PAID = 'paid';

/* Theme Mode Type */
const ThemeModeLight = 0;
const ThemeModeDark = 1;
const THEME_MODE_INDEX = 'theme_mode_index';
const SELECTED_LANGUAGE_CODE = 'selected_language_code';

const default_Language = 'en';

const PENDING = 'Pending';
const APPROVEDText = 'Approved';
const REJECTED = 'Rejected';

const adminEmail = 'admin@admin.com';
const adminPass = '123456';

const get_users_index = 0;
const get_all_event = 1;
const get_all_places = 2;
const add_jackbase_index = 3;
const add_footrest_index = 4;
const add_imageData_index = 5;
const add_product_index = 6;
const add_billingData_index = 7;
const get_billing_index = 8;

const get_mobile_billing_index = 9;

// Currency Position
const CURRENCY_POSITION_LEFT = 'left';
const CURRENCY_POSITION_RIGHT = 'right';

const mAppIconUrl = "assets/app_logo.jpg";

const CREDIT = 'credit';
const DEBIT = 'debit';

// Client Menu Index
const ORDER_LIST_INDEX = 0;
const DRAFT_LIST_INDEX = 1;
const WALLET_INDEX = 2;
const WITHDRAW_HISTORY_INDEX = 3;
const BANK_DETAIL_INDEX = 4;
const CHANGE_PASSWORD_INDEX = 5;
const DELETE_ACCOUNT_INDEX = 6;
const ABOUT_US_INDEX = 7;

const TRANSACTION_ORDER_FEE = "order_fee";
const TRANSACTION_TOPUP = "topup";
const TRANSACTION_ORDER_CANCEL_CHARGE = "order_cancel_charge";
const TRANSACTION_ORDER_CANCEL_REFUND = "order_cancel_refund";
const TRANSACTION_CORRECTION = "correction";
const TRANSACTION_COMMISSION = "commission";
const TRANSACTION_WITHDRAW = "withdraw";

const IS_ENTER_KEY = "IS_ENTER_KEY";
const SELECTED_WALLPAPER = "SELECTED_WALLPAPER";
const PER_PAGE_CHAT_COUNT = 50;

const TEXT = "TEXT";
const IMAGE = "IMAGE";

const VIDEO = "VIDEO";
const AUDIO = "AUDIO";

enum MessageType {
  TEXT,
  IMAGE,
  VIDEO,
  AUDIO,
}

List<String> rtlLanguage = ['ar', 'ur'];

const MONTHLY_ORDER_COUNT = 'monthly_order_count';
const MONTHLY_PAYMENT_CANCELLED_REPORT = 'monthly_payment_cancelled_report';
const MONTHLY_PAYMENT_COMPLETED_REPORT = 'monthly_payment_completed_report';

const mInvoiceCompanyName = 'Roberts Private Limited';
const mInvoiceAddress = 'Sarah Street 9, Beijing, Ahmedabad';
const mInvoiceContactNumber = '+91 9845345665';
