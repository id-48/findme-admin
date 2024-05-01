import 'package:date_time_picker/date_time_picker.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:intl/intl.dart';
import 'package:find_me_admin/models/billing/add_billing/req_billing_data.dart';
import 'package:find_me_admin/models/billing/get_billing/res_billing_data.dart'
as resBillings;
import 'package:find_me_admin/models/billing/update_billing/req_update_billing.dart'
as reqUpdateBilling;
import 'package:find_me_admin/models/product/get_product/res_get_product.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/screens/Admin/get_billing_screen.dart';
import 'package:find_me_admin/utils/Constants.dart';
import 'package:find_me_admin/utils/Extensions/int_extensions.dart';
import 'package:find_me_admin/utils/Extensions/shared_pref.dart';
import 'package:find_me_admin/utils/Extensions/string_extensions.dart';
import 'package:find_me_admin/utils/Extensions/toast.dart';

import '../../components/Admin/BodyCornerWidget.dart';
import '../../main.dart';
import '../../utils/Colors.dart';
import '../../utils/Common.dart';
import '../../utils/Extensions/app_textfield.dart';
import '../../utils/Extensions/constants.dart';
import '../../utils/Extensions/text_styles.dart';
import '../../utils/ResponsiveWidget.dart';

class BillingDataScreen extends StatefulWidget {
  static String route = '/admin/billingData';

  @override
  State<BillingDataScreen> createState() => _BillingDataScreenState();
}

class _BillingDataScreenState extends State<BillingDataScreen> {
  GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  ScrollController horizontalScrollController = ScrollController();
  TextEditingController searchController = TextEditingController();
  TextEditingController nameController = TextEditingController();
  TextEditingController addressController = TextEditingController();
  TextEditingController moNoController = TextEditingController();
  TextEditingController instuctionController = TextEditingController();
  TextEditingController advancePaymentController = TextEditingController();
  TextEditingController deliveryDateControlller = TextEditingController(
      text: "${DateFormat("yyyy-MM-dd").format(DateTime.now())}");

  bool loading = false;
  int totalData = 0;
  int currentPage = 1;
  int totalPage = 1;
  var perPage = 10;
  List<ProductData> searchProductList = [];
  List<ProductData> addProductList = [];
  int totalPrice = 0;

  List<String> paymentList = ['Advance Cash', 'Bank Transfer', 'Card Transfer'];
  String paymentVal = 'Advance Cash';

  String? showRoomName;
  String? uniqShowroomName;
  String billingDate = DateFormat('dd-MM-yyyy').format(DateTime.now());

  int remaingPayment = 0;

  String userLogin = "";
  String showRoomId = "";
  String branchName = "";

  String updateBillingDataId = "";

  bool isUpdate = false;

  @override
  void initState() {
    super.initState();
    print("enter screen initsatet");
    Future.delayed(Duration(milliseconds: 100), () {
      init();
    });
  }

  Future<void> init() async {
    appStore.setSelectedMenuIndex(add_billingData_index);
    upDateData();
  }

  upDateData() async {
    var arg = ModalRoute
        .of(context)!
        .settings
        .arguments;
    print("data value is --->>>${arg}");
    isUpdate = arg != null;
    if (isUpdate) {
      Map<String, resBillings.Billing> billingMainDataJson =
      arg as Map<String, resBillings.Billing>;
      print("arguments :: ${billingMainDataJson['mData']?.toJson()}");

      resBillings.Billing billingMainData =
      resBillings.Billing.fromJson(billingMainDataJson['mData']!.toJson());

      print("data value is json data ----->>${billingMainData} ");

      updateBillingDataId = billingMainData.id.validate();

      nameController.text = billingMainData.name.validate();
      addressController.text = billingMainData.address.validate();
      moNoController.text = billingMainData.mobileNo.validate();
      instuctionController.text = billingMainData.instruction.validate();
      advancePaymentController.text = billingMainData.advanceCash.validate();
      deliveryDateControlller.text = billingMainData.deliveryDate.validate();
      paymentVal = billingMainData.paymentType.validate();
      remaingPayment = billingMainData.remaingCash.validate();
      totalPrice = billingMainData.total.validate();

      for (int i = 0; i < billingMainData.billingData.length; i++) {
        addProductList.add(ProductData(
          id: billingMainData.billingData[i].id,
          image: billingMainData.billingData[i].image,
          imageNumber: billingMainData.billingData[i].modelNumber,
          colors: billingMainData.billingData[i].colors,
          colorSelect: billingMainData.billingData[i].colorSelect,
          designing: billingMainData.billingData[i].designing,
          designSelect: billingMainData.billingData[i].designSelect,
          jackBase: billingMainData.billingData[i].jackBase,
          jackAndBaseSelect: billingMainData.billingData[i].jackAndBaseSelect,
          footrest: billingMainData.billingData[i].footRest,
          footrestSelect: billingMainData.billingData[i].footrestSelect,
          other1Con: TextEditingController(
              text: billingMainData.billingData[i].others1),
          other2Con: TextEditingController(
              text: billingMainData.billingData[i].others2),
          qtyCon: TextEditingController(
              text: "${billingMainData.billingData[i].qty}"),
          priceCon: TextEditingController(
              text: "${billingMainData.billingData[i].price}"),
          totalPrice:
          "${int.parse("${billingMainData.billingData[i].qty}") *
              double.parse("${billingMainData.billingData[i].price}")}",
        ));
      }
    }

    userLogin = await getString("userLogin");
    showRoomName = await getString("showRoomName");
    showRoomId = await getString("showroomId");
    uniqShowroomName = userLogin == "showRoom"
        ? showRoomName!.substring(0, 4).toUpperCase()
        : "ADMIN";
    branchName =
    userLogin == "showRoom" ? showRoomName!.toUpperCase() : "ADMIN";
    setState(() {});
  }

  Future totalPageValue() async {
    totalPage = (totalData / perPage).ceil();
    print("total page -->>$totalPage");
    setState(() {});
  }

  String generateBillNumber(String showroomName, int numbers) {
    print("nextNumbers83 : $numbers ");

    int nextNumbers = numbers + 1;
    print("nextNumbers : $nextNumbers");
    setState(() {});
    return '$showroomName$nextNumbers';
  }

  onGetSearchProductList(String searchVal) async {
    loading = true;
    setState(() {});
    await getSearchProduct(searchVal: searchVal).then((value) {
      if (value.status == true) {
        print("api calll  screeen---->>");
        // totalData = value.totalProduct;
        loading = false;
        searchProductList = value.product;
        setState(() {});
      }
    });
  }

  onAddProductDataTap(ProductData productData) {
    if (addProductList == []
        ? false
        : addProductList
        .where((element) => element.id == productData.id)
        .isNotEmpty) {
      ToastUtils.showCustomToast(
          context, "You have all ready added.", "warning");
    } else {
      addProductList.add(ProductData(
        id: productData.id,
        image: productData.image,
        imageNumber: productData.imageNumber,
        productName: productData.productName,
        colors: productData.colors,
        colorSelect: productData.colors[0],
        designing: productData.designing,
        designSelect: productData.designing[0],
        jackBase: productData.jackBase,
        jackAndBaseSelect: productData.jackBase[0],
        footrest: productData.footrest,
        footrestSelect: productData.footrest[0],
        createdAt: productData.createdAt,
        updatedAt: productData.updatedAt,
        other1Con: TextEditingController(text: ""),
        other2Con: TextEditingController(text: ""),
        qtyCon: TextEditingController(text: "1"),
        priceCon: TextEditingController(text: "0"),
        totalPrice: "0",
      ));
      print("data add product   ---->>${addProductList[0].toJson()}");
      setState(() {});
    }
  }

  addBillingDataApi() async {
    List<BillingDatum> billingList = [];

    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);

      for (int i = 0; i < addProductList.length; i++) {
        billingList.add(BillingDatum(
            image: addProductList[i].image,
            modelNumber: addProductList[i].imageNumber,
            colors: addProductList[i].colors,
            designing: addProductList[i].designing,
            jackBase: addProductList[i].jackBase,
            footRest: addProductList[i].footrest,
            others1: addProductList[i].other1Con!.text.trim() ?? "",
            others2: addProductList[i].other2Con!.text.trim() ?? "",
            qty: addProductList[i].qtyCon!.text.trim() ?? "",
            price: addProductList[i].priceCon!.text.trim() ?? "",
            colorSelect: addProductList[i].colorSelect ?? "",
            designSelect: addProductList[i].designSelect ?? "",
            jackAndBaseSelect: addProductList[i].jackAndBaseSelect ?? "",
            footrestSelect: addProductList[i].footrestSelect ?? ""));
      }

      ReqBilling billingData = ReqBilling(
        billNo: BillingNumberGenerator.generateNextNumber(uniqShowroomName),
        billingDate: billingDate,
        branchName: userLogin == "showRoom"
            ? showRoomName!.substring(0, 4).toUpperCase()
            : "ADMIN",
        name: nameController.text.trim(),
        address: addressController.text.trim(),
        deliveryDate: deliveryDateControlller.text.trim(),
        mobileNo: moNoController.text.trim(),
        instruction: instuctionController.text.trim(),
        billingData: billingList,
        total: totalPrice.toString(),
        paymentType: paymentVal,
        advanceCash: advancePaymentController.text.trim(),
        remaingCash: remaingPayment.toString(),
        showroomId: userLogin == "showRoom" ? showRoomId : "ADMIN",
      );

      await addBilling(req: billingData).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");

          Navigator.pushNamed(context, GetBillingScreen.route);
        } else {
          ToastUtils.showCustomToast(context, value.message, "warning");
        }
      });
    }
  }

  updateBillingApi() async {
    List<reqUpdateBilling.BillingDatum> billingList = [];

    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);

      for (int i = 0; i < addProductList.length; i++) {
        billingList.add(reqUpdateBilling.BillingDatum(
            image: addProductList[i].image,
            modelNumber: addProductList[i].imageNumber,
            colors: addProductList[i].colors,
            designing: addProductList[i].designing,
            jackBase: addProductList[i].jackBase,
            footRest: addProductList[i].footrest,
            others1: addProductList[i].other1Con!.text.trim() ?? "",
            others2: addProductList[i].other2Con!.text.trim() ?? "",
            qty: addProductList[i].qtyCon!.text.trim() ?? "",
            price: addProductList[i].priceCon!.text.trim() ?? "",
            colorSelect: addProductList[i].colorSelect ?? "",
            designSelect: addProductList[i].designSelect ?? "",
            jackAndBaseSelect: addProductList[i].jackAndBaseSelect ?? "",
            footrestSelect: addProductList[i].footrestSelect ?? ""));
      }

      reqUpdateBilling.ReqUpdateBilling updateBillingData =
      reqUpdateBilling.ReqUpdateBilling(
        billingId: updateBillingDataId,
        billNo: BillingNumberGenerator.generateNextNumber(uniqShowroomName),
        billingDate: billingDate,
        branchName: userLogin == "showRoom"
            ? showRoomName!.substring(0, 4).toUpperCase()
            : "ADMIN",
        name: nameController.text.trim(),
        address: addressController.text.trim(),
        deliveryDate: deliveryDateControlller.text.trim(),
        mobileNo: moNoController.text.trim(),
        instruction: instuctionController.text.trim(),
        billingData: billingList,
        total: totalPrice.toString(),
        paymentType: paymentVal,
        advanceCash: advancePaymentController.text.trim(),
        remaingCash: remaingPayment.toString(),
        showroomId: userLogin == "showRoom" ? showRoomId : "ADMIN",
      );

      await updateBilling(req: updateBillingData).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");
          Navigator.pushNamed(context, GetBillingScreen.route);
        } else {
          ToastUtils.showCustomToast(context, value.message, "warning");
        }
      });
    }
  }

  @override
  void setState(fn) {
    if (mounted) super.setState(fn);
  }

  @override
  Widget build(BuildContext context) {
    return Observer(builder: (context) {
      return BodyCornerWidget(
        child: Stack(
          fit: StackFit.expand,
          children: [
            SingleChildScrollView(
              physics: BouncingScrollPhysics(),
              padding: EdgeInsets.all(16),
              scrollDirection: Axis.vertical,
              controller: ScrollController(),
              child: Form(
                key: _formKey,
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    ResponsiveWidget.isSmallScreen(context) &&
                        appStore.isMenuExpanded
                        ? Wrap(
                      spacing: 16,
                      runSpacing: 16,
                      crossAxisAlignment: WrapCrossAlignment.center,
                      children: [
                        Text(
                            isUpdate
                                ? "Update Billing Data"
                                : "Add Billing Data",
                            style: boldTextStyle(
                                size: 20, color: primaryColor)),
                        // addImageDataButton(),
                      ],
                    )
                        : Row(
                      mainAxisAlignment: MainAxisAlignment.spaceBetween,
                      children: [
                        Text(
                            isUpdate
                                ? "Update Billing Data"
                                : "Add Billing Data",
                            style: boldTextStyle(
                                size: 20, color: primaryColor)),
                      ],
                    ),
                    Column(
                      mainAxisAlignment: MainAxisAlignment.start,
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Padding(
                          padding: const EdgeInsets.all(20),
                          child: Row(
                            children: [
                              Expanded(
                                child: Container(
                                  decoration: BoxDecoration(
                                      color: Colors.white,
                                      borderRadius:
                                      BorderRadius.circular(defaultRadius),
                                      boxShadow: commonBoxShadow()),
                                  child: Padding(
                                    padding: const EdgeInsets.all(20),
                                    child: Column(
                                      children: [
                                        Row(
                                          mainAxisAlignment:
                                          MainAxisAlignment.spaceBetween,
                                          children: [
                                            Row(
                                              children: [
                                                Text(
                                                  'Show Room Name : ',
                                                  style: TextStyle(
                                                      fontWeight:
                                                      FontWeight.w700,
                                                      fontSize: 14),
                                                ),
                                                SizedBox(
                                                  width: 10,
                                                ),
                                                Container(
                                                  padding: EdgeInsets.symmetric(
                                                      vertical: 15,
                                                      horizontal: 15),
                                                  decoration: BoxDecoration(
                                                      color: Colors.grey
                                                          .withOpacity(0.15),
                                                      borderRadius:
                                                      BorderRadius.circular(
                                                          defaultRadius)),
                                                  child: Text(
                                                    "${branchName}",
                                                    style: TextStyle(
                                                        fontWeight:
                                                        FontWeight.w700,
                                                        fontSize: 14),
                                                  ),
                                                ),
                                              ],
                                            ),
                                            20.width,
                                            Row(
                                              children: [
                                                Text(
                                                  'Billing date : ',
                                                  style: TextStyle(
                                                      fontWeight:
                                                      FontWeight.w700,
                                                      fontSize: 14),
                                                ),
                                                10.width,
                                                Container(
                                                  padding: EdgeInsets.symmetric(
                                                      vertical: 15,
                                                      horizontal: 15),
                                                  decoration: BoxDecoration(
                                                      color: Colors.grey
                                                          .withOpacity(0.15),
                                                      borderRadius:
                                                      BorderRadius.circular(
                                                          defaultRadius)),
                                                  child: Text(
                                                    "$billingDate",
                                                    style: TextStyle(
                                                        fontWeight:
                                                        FontWeight.w700,
                                                        fontSize: 14),
                                                  ),
                                                ),
                                              ],
                                            ),
                                          ],
                                        ),
                                        20.height,
                                        Row(
                                          children: [
                                            Row(
                                              children: [
                                                Text(
                                                  'Name : ',
                                                  style: TextStyle(
                                                      fontWeight:
                                                      FontWeight.w700,
                                                      fontSize: 14),
                                                ),
                                                SizedBox(
                                                  width: MediaQuery
                                                      .of(context)
                                                      .size
                                                      .width /
                                                      4,
                                                  child: AppTextField(
                                                    controller: nameController,
                                                    textFieldType:
                                                    TextFieldType.NAME,
                                                    decoration:
                                                    commonInputDecoration(),
                                                    textInputAction:
                                                    TextInputAction.next,
                                                    errorThisFieldRequired:
                                                    "This field is required",
                                                  ),
                                                )
                                                // CustomTextFields(textController: billNoController)
                                              ],
                                            ),
                                            20.width,
                                            Row(
                                              children: [
                                                Text(
                                                  'Mobile No : ',
                                                  style: TextStyle(
                                                      fontWeight:
                                                      FontWeight.w700,
                                                      fontSize: 14),
                                                ),
                                                SizedBox(
                                                  width: 200,
                                                  child: AppTextField(
                                                    controller: moNoController,
                                                    textInputAction:
                                                    TextInputAction.next,
                                                    textFieldType:
                                                    TextFieldType.PHONE,
                                                    maxLength: 10,
                                                    decoration:
                                                    commonInputDecoration(),
                                                    validator: (value) {
                                                      if (value!.trim().isEmpty)
                                                        return errorThisFieldRequired;
                                                      if (value
                                                          .trim()
                                                          .length <
                                                          minContactLength)
                                                        return "Number should be 10 digits only";
                                                      return null;
                                                    },
                                                    inputFormatters: [
                                                      FilteringTextInputFormatter
                                                          .digitsOnly,
                                                    ],
                                                  ),
                                                )
                                                // CustomTextFields(textController: billNoController)
                                              ],
                                            ),
                                          ],
                                        ),
                                        20.height,
                                        Row(
                                          children: [
                                            Row(
                                              children: [
                                                Text(
                                                  'Address : ',
                                                  style: TextStyle(
                                                      fontWeight:
                                                      FontWeight.w700,
                                                      fontSize: 14),
                                                ),
                                                SizedBox(
                                                  width: MediaQuery
                                                      .of(context)
                                                      .size
                                                      .width /
                                                      4,
                                                  child: AppTextField(
                                                    controller:
                                                    addressController,
                                                    textFieldType:
                                                    TextFieldType.NAME,
                                                    decoration:
                                                    commonInputDecoration(),
                                                    maxLines: 3,
                                                    minLines: 3,
                                                    textInputAction:
                                                    TextInputAction.next,
                                                    errorThisFieldRequired:
                                                    "This field is required",
                                                  ),
                                                ),
                                              ],
                                            ),
                                            20.width,
                                            Expanded(
                                              child: Row(
                                                children: [
                                                  Text(
                                                    'Delivery date : ',
                                                    style: TextStyle(
                                                        fontWeight:
                                                        FontWeight.w700,
                                                        fontSize: 14),
                                                  ),
                                                  10.width,
                                                  Expanded(
                                                    child: DateTimePicker(
                                                      controller:
                                                      deliveryDateControlller,
                                                      type: DateTimePickerType
                                                          .date,
                                                      dateMask: "dd/MM/yyyy",
                                                      lastDate: DateTime(2100),
                                                      firstDate: DateTime(2010),
                                                      onChanged: (value) {
                                                        setState(() {});
                                                      },
                                                      decoration:
                                                      commonInputDecoration(
                                                          suffixIcon: Icon(
                                                              Icons
                                                                  .date_range),
                                                          hintText: "Date"),
                                                    ),
                                                  ),
                                                ],
                                              ),
                                            ),
                                          ],
                                        ),
                                        20.height,
                                        Row(
                                          children: [
                                            Text(
                                              'Instruction : ',
                                              style: TextStyle(
                                                  fontWeight: FontWeight.w700,
                                                  fontSize: 14),
                                            ),
                                            SizedBox(
                                              width: MediaQuery
                                                  .of(context)
                                                  .size
                                                  .width /
                                                  4,
                                              child: AppTextField(
                                                controller:
                                                instuctionController,
                                                textFieldType:
                                                TextFieldType.NAME,
                                                decoration:
                                                commonInputDecoration(),
                                                textInputAction:
                                                TextInputAction.next,
                                                errorThisFieldRequired:
                                                "This field is required",
                                              ),
                                            )
                                            // CustomTextFields(textController: billNoController)
                                          ],
                                        ),
                                      ],
                                    ),
                                  ),
                                ),
                              ),
                              SizedBox(
                                height: MediaQuery
                                    .of(context)
                                    .size
                                    .width / 6.5,
                                width: MediaQuery
                                    .of(context)
                                    .size
                                    .width / 4,
                                child: Image.asset(
                                  'assets/app_logo_primary.png',
                                  fit: BoxFit.fill,
                                ),
                              )
                            ],
                          ),
                        ),
                        Padding(
                          padding: const EdgeInsets.symmetric(vertical: 20),
                          child: SizedBox(
                            width: MediaQuery
                                .of(context)
                                .size
                                .width / 4,
                            child: AppTextField(
                              maxLines: 1,
                              controller: searchController,
                              textFieldType: TextFieldType.NAME,
                              decoration: commonInputDecoration(
                                prefixIcon: Icon(Icons.search),
                                labelText: "Product Search...",
                                suffixIcon: searchProductList.length > 0
                                    ? InkWell(
                                  onTap: () {
                                    searchProductList.clear();
                                    searchController.clear();
                                    setState(() {});
                                  },
                                  child: Padding(
                                    padding: const EdgeInsets.all(5.0),
                                    child: CircleAvatar(
                                      child: Icon(
                                        Icons.close,
                                        color: Colors.white,
                                        size: 20,
                                      ),
                                      backgroundColor: Colors.red,
                                      radius: 14,
                                    ),
                                  ),
                                )
                                    : null,
                              ),
                              textInputAction: TextInputAction.next,
                              validator: (val) {
                                return null;
                              },
                              onChanged: (val) {
                                searchProductList.clear();
                                setState(() {});

                                String value = val.trim();
                                if (value.isNotEmpty) {
                                  if (value.length > 0) {
                                    //2
                                    onGetSearchProductList(value);
                                  }
                                }
                              },
                            ),
                          ),
                        ),
                        if (loading) ...[
                          10.height,
                          SizedBox(
                              height: 50,
                              width: 50,
                              child: CircularProgressIndicator(
                                color: primaryColor,
                              )),
                          30.height,
                        ] else
                          if (searchController.text
                              .trim()
                              .length > 2 &&
                              searchProductList.length == 0) ...[
                            Text(
                              "No Data Found...",
                              style: TextStyle(
                                  fontWeight: FontWeight.w700, fontSize: 14),
                            ),
                            30.height,
                          ],
                        if (searchProductList.isNotEmpty) ...[
                          Wrap(
                            // runSpacing: 30,
                            spacing: 20,
                            runSpacing: 20,
                            children:
                            searchProductList.map((searchProductData) {
                              return Container(
                                width: 300,
                                padding: EdgeInsets.symmetric(
                                    horizontal: 16, vertical: 8),
                                decoration: BoxDecoration(
                                  border: Border.all(color: primaryColor),
                                  borderRadius: BorderRadius.circular(12),
                                ),
                                child: Row(
                                  children: [
                                    commonCachedNetworkImage(
                                        "${mBaseUrl + searchProductData.image}",
                                        fit: BoxFit.fill,
                                        height: 70,
                                        width: 70),
                                    10.width,
                                    Expanded(
                                      child: Text(
                                        "${searchProductData.productName}",
                                        style: TextStyle(
                                          fontWeight: FontWeight.w500,
                                        ),
                                        maxLines: 1,
                                        overflow: TextOverflow.ellipsis,
                                      ),
                                    ),
                                    10.width,
                                    InkWell(
                                      onTap: () {
                                        onAddProductDataTap(searchProductData);
                                      },
                                      child: Container(
                                        padding: EdgeInsets.symmetric(
                                            horizontal: 20, vertical: 6),
                                        decoration: BoxDecoration(
                                          color: Color(0xff00c853),
                                          borderRadius:
                                          BorderRadius.circular(12),
                                        ),
                                        child: Text(
                                          "+ Add",
                                          style: TextStyle(color: Colors.white),
                                        ),
                                      ),
                                    ),
                                  ],
                                ),
                              );
                            }).toList(),
                          ),
                          30.height,
                        ],
                        Padding(
                          padding: const EdgeInsets.only(left: 20, right: 20),
                          child: ConstrainedBox(
                            constraints: BoxConstraints(
                                minWidth: getBodyWidth(context) - 48),
                            child: DataTable(
                              // dataRowHeight: 60,
                              dataRowMaxHeight: 420,
                              // dataRowMinHeight: 300,
                              headingRowHeight: 45,
                              horizontalMargin: 16,
                              headingRowColor: MaterialStateColor.resolveWith(
                                      (states) =>
                                      primaryColor.withOpacity(0.1)),
                              showCheckboxColumn: false,
                              dataTextStyle: primaryTextStyle(size: 14),
                              headingTextStyle: boldTextStyle(),
                              columns: [
                                DataColumn(label: Text("SR.No")),
                                DataColumn(label: Text("Model Name")),
                                DataColumn(label: Text("Image")),
                                DataColumn(
                                    label: Text("Model Data And Details")),
                                DataColumn(label: Text("Qty")),
                                DataColumn(label: Text("Price")),
                                DataColumn(label: Text("Total")),
                              ],
                              rows: addProductList.map((mData) {
                                return DataRow(cells: [

                                  ///  Sr.No
                                  DataCell(
                                    Text(
                                      '${addProductList.indexOf(mData) + 1}',
                                      style: TextStyle(
                                          fontWeight: FontWeight.w700,
                                          fontSize: 14),
                                    ),
                                  ),

                                  /// Model Name
                                  DataCell(
                                    Text(
                                      "${mData.imageNumber}",
                                      style: TextStyle(
                                          fontWeight: FontWeight.w700,
                                          fontSize: 14),
                                    ),
                                  ),

                                  /// Image
                                  DataCell(
                                    Container(
                                      color: Colors.green.shade100,
                                      height: 200,
                                      width: 200,
                                      child: commonCachedNetworkImage(
                                          "${mBaseUrl + mData.image}",
                                          fit: BoxFit.fill,
                                          height: 200,
                                          width: 200),
                                    ),
                                  ),

                                  /// Model data And Details
                                  DataCell(
                                    SizedBox(
                                      width: 250,
                                      child: SingleChildScrollView(
                                        child: Column(
                                          children: [
                                            40.height,
                                            Row(
                                              children: [
                                                Expanded(
                                                  flex: 2,
                                                  child: Text(
                                                    'Colour',
                                                    style: TextStyle(
                                                        fontWeight:
                                                        FontWeight.w700,
                                                        fontSize: 14),
                                                  ),
                                                ),
                                                Expanded(
                                                  flex: 7,
                                                  child:
                                                  DropdownButtonFormField<
                                                      String>(
                                                    dropdownColor:
                                                    Theme
                                                        .of(context)
                                                        .cardColor,
                                                    // value: "1",
                                                    value: mData.colorSelect,
                                                    decoration:
                                                    commonInputDecoration(),
                                                    items: mData.colors
                                                        .toList()
                                                        .map<
                                                        DropdownMenuItem<
                                                            String>>((String
                                                    item) {
                                                      return DropdownMenuItem(
                                                          value: item,
                                                          child: Text(item,
                                                              style:
                                                              primaryTextStyle()));
                                                    }).toList(),
                                                    onChanged: (value) {
                                                      mData.colorSelect =
                                                          value!.validate();
                                                      setState(() {});
                                                    },
                                                    validator: (value) {
                                                      if (mData.colorSelect
                                                          .isEmptyOrNull)
                                                        return "This field is required";
                                                      return null;
                                                    },
                                                  ),
                                                ),
                                              ],
                                            ),
                                            8.height,
                                            Row(
                                              children: [
                                                Expanded(
                                                  flex: 2,
                                                  child: Text(
                                                    'Design',
                                                    style: TextStyle(
                                                        fontWeight:
                                                        FontWeight.w700,
                                                        fontSize: 14),
                                                  ),
                                                ),
                                                Expanded(
                                                  flex: 7,
                                                  child:
                                                  DropdownButtonFormField<
                                                      String>(
                                                    dropdownColor:
                                                    Theme
                                                        .of(context)
                                                        .cardColor,
                                                    value: mData.designSelect,
                                                    decoration:
                                                    commonInputDecoration(),
                                                    items: mData.designing
                                                        .toList()
                                                        .map<
                                                        DropdownMenuItem<
                                                            String>>((String
                                                    item) {
                                                      return DropdownMenuItem(
                                                          value: item,
                                                          child: Text(item,
                                                              style:
                                                              primaryTextStyle()));
                                                    }).toList(),
                                                    onChanged: (value) {
                                                      mData.designSelect =
                                                          value!.validate();
                                                      setState(() {});
                                                    },
                                                    validator: (value) {
                                                      if (mData.designSelect
                                                          .isEmptyOrNull)
                                                        return "This field is required";
                                                      return null;
                                                    },
                                                  ),
                                                ),
                                              ],
                                            ),
                                            8.height,
                                            Row(
                                              children: [
                                                Expanded(
                                                  flex: 2,
                                                  child: Text(
                                                    'Jack & Base',
                                                    style: TextStyle(
                                                        fontWeight:
                                                        FontWeight.w700,
                                                        fontSize: 14),
                                                  ),
                                                ),
                                                Expanded(
                                                  flex: 7,
                                                  child:
                                                  DropdownButtonFormField<
                                                      String>(
                                                    dropdownColor:
                                                    Theme
                                                        .of(context)
                                                        .cardColor,
                                                    value:
                                                    mData.jackAndBaseSelect,
                                                    decoration:
                                                    commonInputDecoration(),
                                                    items: mData.jackBase
                                                        .toList()
                                                        .map<
                                                        DropdownMenuItem<
                                                            String>>((String
                                                    item) {
                                                      return DropdownMenuItem(
                                                          value: item,
                                                          child: Text(item,
                                                              style:
                                                              primaryTextStyle()));
                                                    }).toList(),
                                                    onChanged: (value) {
                                                      mData.jackAndBaseSelect =
                                                          value!.validate();
                                                      setState(() {});
                                                    },
                                                    validator: (value) {
                                                      if (mData
                                                          .jackAndBaseSelect
                                                          .isEmptyOrNull)
                                                        return "This field is required";
                                                      return null;
                                                    },
                                                  ),
                                                ),
                                              ],
                                            ),
                                            8.height,
                                            Row(
                                              children: [
                                                Expanded(
                                                  flex: 2,
                                                  child: Text(
                                                    'Footrest',
                                                    style: TextStyle(
                                                        fontWeight:
                                                        FontWeight.w700,
                                                        fontSize: 14),
                                                  ),
                                                ),
                                                Expanded(
                                                  flex: 7,
                                                  child:
                                                  DropdownButtonFormField<
                                                      String>(
                                                    dropdownColor:
                                                    Theme
                                                        .of(context)
                                                        .cardColor,
                                                    value: mData.footrestSelect,
                                                    decoration:
                                                    commonInputDecoration(),
                                                    items: mData.footrest
                                                        .toList()
                                                        .map<
                                                        DropdownMenuItem<
                                                            String>>((String
                                                    item) {
                                                      return DropdownMenuItem(
                                                          value: item,
                                                          child: Text(item,
                                                              style:
                                                              primaryTextStyle()));
                                                    }).toList(),
                                                    onChanged: (value) {
                                                      mData.footrestSelect =
                                                          value!.validate();
                                                      setState(() {});
                                                    },
                                                    validator: (value) {
                                                      if (mData.footrestSelect
                                                          .isEmptyOrNull)
                                                        return "This field is required";
                                                      return null;
                                                    },
                                                  ),
                                                ),
                                              ],
                                            ),
                                            8.height,
                                            Row(
                                              children: [
                                                Expanded(
                                                  flex: 2,
                                                  child: Text(
                                                    'Other1',
                                                    style: TextStyle(
                                                        fontWeight:
                                                        FontWeight.w700,
                                                        fontSize: 14),
                                                  ),
                                                ),
                                                Expanded(
                                                  flex: 7,
                                                  child: AppTextField(
                                                    maxLines: 1,
                                                    controller:
                                                    mData.other1Con!,
                                                    textFieldType:
                                                    TextFieldType.OTHER,
                                                    textInputAction:
                                                    TextInputAction.next,
                                                    decoration:
                                                    commonInputDecoration(),
                                                    validator: (val) {
                                                      return null;
                                                    },
                                                    errorThisFieldRequired:
                                                    "This field is required",
                                                  ),
                                                ),
                                              ],
                                            ),
                                            8.height,
                                            Row(
                                              children: [
                                                Expanded(
                                                  flex: 2,
                                                  child: Text(
                                                    'Other2',
                                                    style: TextStyle(
                                                        fontWeight:
                                                        FontWeight.w700,
                                                        fontSize: 14),
                                                  ),
                                                ),
                                                Expanded(
                                                  flex: 7,
                                                  child: AppTextField(
                                                    maxLines: 1,
                                                    controller:
                                                    mData.other2Con!,
                                                    textFieldType:
                                                    TextFieldType.OTHER,
                                                    textInputAction:
                                                    TextInputAction.next,
                                                    decoration:
                                                    commonInputDecoration(),
                                                    validator: (val) {
                                                      return null;
                                                    },
                                                    errorThisFieldRequired:
                                                    "This field is required",
                                                  ),
                                                ),
                                              ],
                                            ),
                                            10.height,
                                          ],
                                        ),
                                      ),
                                    ),
                                  ),

                                  /// Qty
                                  DataCell(
                                    SizedBox(
                                      width: MediaQuery
                                          .of(context)
                                          .size
                                          .width /
                                          18,
                                      child: AppTextField(
                                        maxLines: 1,
                                        controller: mData.qtyCon!,
                                        textFieldType: TextFieldType.PHONE,
                                        textInputAction: TextInputAction.next,
                                        decoration: commonInputDecoration(),
                                        validator: (val) {
                                          return null;
                                        },
                                        onChanged: (val) {
                                          String value = val.trim();
                                          if (value.isEmpty) {
                                            mData.qtyCon =
                                                TextEditingController(
                                                    text: "1");
                                          }

                                          print(
                                              "data value qty And price ---->>> #${(int
                                                  .parse("${mData.qtyCon
                                                  ?.text}"))} ${(double.parse(
                                                  "${mData.priceCon
                                                      ?.text}"))}");
                                          mData.totalPrice =
                                          "${(int.parse("${mData.qtyCon
                                              ?.text}")) *
                                              (double.parse("${mData.priceCon
                                                  ?.text}"))}";

                                          totalPrice = 0;
                                          for (int i = 0;
                                          i < addProductList.length;
                                          i++) {
                                            totalPrice += (addProductList[i]
                                                .totalPrice
                                                .toInt());
                                          }
                                          setState(() {});
                                        },
                                        errorThisFieldRequired:
                                        "This field is required",
                                        inputFormatters: [
                                          FilteringTextInputFormatter
                                              .digitsOnly,
                                        ],
                                      ),
                                    ),
                                  ),

                                  /// Price
                                  DataCell(
                                    SizedBox(
                                      width: MediaQuery
                                          .of(context)
                                          .size
                                          .width /
                                          15,
                                      child: AppTextField(
                                        maxLines: 1,
                                        controller: mData.priceCon!,
                                        textFieldType: TextFieldType.PHONE,
                                        textInputAction: TextInputAction.next,
                                        decoration: commonInputDecoration(),
                                        validator: (val) {
                                          double value = double.parse("${val}");
                                          if (value <= 0.0) {
                                            return "Please enter price.";
                                          }

                                          return null;
                                        },
                                        onChanged: (val) {
                                          print(
                                              "data price controllerval ---->>3${val}");
                                          String value = val.trim();
                                          if (value.isEmpty) {
                                            mData.priceCon =
                                                TextEditingController(
                                                    text: "0");
                                          }
                                          print(
                                              "data value qty And price ---->>> #${(int
                                                  .parse("${mData.qtyCon
                                                  ?.text}"))} ${(double.parse(
                                                  "${mData.priceCon
                                                      ?.text}"))}");

                                          mData.totalPrice =
                                          "${(int.parse("${mData.qtyCon
                                              ?.text}")) *
                                              (double.parse("${mData.priceCon
                                                  ?.text}"))}";
                                          totalPrice = 0;
                                          for (int i = 0;
                                          i < addProductList.length;
                                          i++) {
                                            totalPrice += (addProductList[i]
                                                .totalPrice
                                                .toInt());
                                          }
                                          setState(() {});
                                        },
                                        errorThisFieldRequired:
                                        "This field is required",
                                        inputFormatters: [
                                          FilteringTextInputFormatter.allow(
                                              RegExp(r'^\d+\.?\d{0,2}')),
                                        ],
                                      ),
                                    ),
                                  ),

                                  ///  Total
                                  DataCell(
                                    Padding(
                                      padding: const EdgeInsets.symmetric(
                                          vertical: 30),
                                      child: Column(
                                        mainAxisAlignment:
                                        MainAxisAlignment.spaceBetween,
                                        children: [
                                          InkWell(
                                            onTap: () {
                                              addProductList.removeAt(
                                                  addProductList
                                                      .indexOf(mData));
                                              setState(() {});
                                            },
                                            child: CircleAvatar(
                                              child: Padding(
                                                padding:
                                                const EdgeInsets.all(0.0),
                                                child: Icon(
                                                  Icons.close,
                                                  color: Colors.white,
                                                  size: 20,
                                                ),
                                              ),
                                              backgroundColor: Colors.red,
                                              radius: 16,
                                            ),
                                          ),
                                          Text(
                                            '${mData.totalPrice}',
                                            style: TextStyle(
                                                fontWeight: FontWeight.w700,
                                                fontSize: 14),
                                          ),
                                          Icon(Icons.close,
                                              color: Colors.white),
                                        ],
                                      ),
                                    ),
                                  ),
                                ]);
                              }).toList(),
                            ),
                          ),
                        ),
                        Padding(
                          padding: const EdgeInsets.only(top: 20, bottom: 80),
                          child: Container(
                              decoration: BoxDecoration(
                                  color: Colors.white,
                                  borderRadius:
                                  BorderRadius.circular(defaultRadius),
                                  boxShadow: commonBoxShadow()),
                              child: Padding(
                                padding: const EdgeInsets.all(10),
                                child: Column(
                                  crossAxisAlignment: CrossAxisAlignment.end,
                                  mainAxisAlignment: MainAxisAlignment.end,
                                  children: [
                                    Padding(
                                      padding: const EdgeInsets.all(8.0),
                                      child: Text(
                                        'Total :    ${totalPrice}',
                                        style: TextStyle(
                                            fontWeight: FontWeight.w700,
                                            fontSize: 14),
                                      ),
                                    ),
                                    Padding(
                                      padding: const EdgeInsets.all(8.0),
                                      child: Row(
                                        mainAxisAlignment:
                                        MainAxisAlignment.end,
                                        children: [
                                          Text(
                                            'Advance Payment Type :',
                                            style: TextStyle(
                                                fontWeight: FontWeight.w700,
                                                fontSize: 14),
                                          ),
                                          SizedBox(
                                            width: 10,
                                          ),
                                          SizedBox(
                                            width: 200,
                                            child:
                                            DropdownButtonFormField<String>(
                                              dropdownColor:
                                              Theme
                                                  .of(context)
                                                  .cardColor,
                                              value: paymentVal,
                                              decoration:
                                              commonInputDecoration(),
                                              items: paymentList.map<
                                                  DropdownMenuItem<String>>(
                                                      (item) {
                                                    return DropdownMenuItem(
                                                        value: item,
                                                        child: Text(item,
                                                            style:
                                                            primaryTextStyle()));
                                                  }).toList(),
                                              onChanged: (value) {
                                                paymentVal = value!.validate();
                                                setState(() {});
                                              },
                                              validator: (value) {
                                                if (paymentVal.isEmptyOrNull)
                                                  return "This field is required";
                                                return null;
                                              },
                                            ),
                                          ),
                                        ],
                                      ),
                                    ),
                                    Padding(
                                      padding: const EdgeInsets.all(8.0),
                                      child: Row(
                                        mainAxisAlignment:
                                        MainAxisAlignment.end,
                                        children: [
                                          Text(
                                            'Advance : ',
                                            style: TextStyle(
                                                fontWeight: FontWeight.w700,
                                                fontSize: 14),
                                          ),
                                          SizedBox(
                                            width: 10,
                                          ),
                                          SizedBox(
                                            width: MediaQuery
                                                .of(context)
                                                .size
                                                .width /
                                                6,
                                            child: SizedBox(
                                              width: 200,
                                              child: AppTextField(
                                                onChanged: (val) {
                                                  remaingPayment = totalPrice -
                                                      int.parse(
                                                          advancePaymentController
                                                              .text
                                                              .trim());
                                                  setState(() {});
                                                },
                                                controller:
                                                advancePaymentController,
                                                textFieldType:
                                                TextFieldType.PHONE,
                                                decoration:
                                                commonInputDecoration(),
                                                textInputAction:
                                                TextInputAction.next,
                                                errorThisFieldRequired:
                                                "This field is required",
                                              ),
                                            ),
                                          )
                                          // CustomTextFields(textController: billNoController)
                                        ],
                                      ),
                                    ),
                                    Padding(
                                      padding: const EdgeInsets.all(8.0),
                                      child: Row(
                                        mainAxisAlignment:
                                        MainAxisAlignment.end,
                                        children: [
                                          Text(
                                            'Remaining Payment :  ${remaingPayment}',
                                            style: TextStyle(
                                                fontWeight: FontWeight.w700,
                                                fontSize: 14),
                                          ),
                                          SizedBox(
                                            width: 10,
                                          ),

                                          // CustomTextFields(textController: billNoController)
                                        ],
                                      ),
                                    ),
                                  ],
                                ),
                              )),
                        ),
                        Center(
                          child:
                          commonButton(isUpdate ? "Update" : "Submit", () {
                            if (isUpdate) {
                              updateBillingApi();
                            } else {
                              addBillingDataApi();
                            }
                          }, width: 200),
                        ),
                        60.height
                      ],
                    )
                  ],
                ),
              ),
            ),
          ],
        ),
      );
    });
  }
}

class BillingNumberGenerator {
  static int _counter = 1;

  static String generateNextNumber(String? showroomName) {
    String nextImageNumber = '$showroomName$_counter';
    _counter++;
    return nextImageNumber;
  }
}

class SearchBar extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Container(
      padding: EdgeInsets.all(16),
      child: TextField(
        decoration: InputDecoration(
          fillColor: Colors.blue.shade300,
          labelText: 'Search..',
          border: OutlineInputBorder(
              borderRadius: BorderRadius.all(Radius.circular(100))),
          prefixIcon: Icon(Icons.search),
        ),
      ),
    );
  }
}

class CustomTextFields extends StatelessWidget {
  CustomTextFields({
    required this.textController,
  });

  TextEditingController textController = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return AppTextField(
      maxLines: 3,
      controller: textController,
      textFieldType: TextFieldType.NAME,
      decoration: commonInputDecoration(),
      textInputAction: TextInputAction.next,
      errorThisFieldRequired: "This field is required",
    );
  }
}
