import 'dart:convert';

ReqBilling reqBillingFromJson(String str) =>
    ReqBilling.fromJson(json.decode(str));

String reqBillingToJson(ReqBilling data) => json.encode(data.toJson());

class ReqBilling {
  String billNo;
  String billingDate;
  String showroomId;
  String branchName;
  String name;
  String address;
  String deliveryDate;
  String mobileNo;
  String instruction;
  List<BillingDatum> billingData;
  String total;
  String paymentType;
  String advanceCash;
  String remaingCash;

  ReqBilling({
    required this.billNo,
    required this.billingDate,
    required this.showroomId,
    required this.branchName,
    required this.name,
    required this.address,
    required this.deliveryDate,
    required this.mobileNo,
    required this.instruction,
    required this.billingData,
    required this.total,
    required this.paymentType,
    required this.advanceCash,
    required this.remaingCash,
  });

  factory ReqBilling.fromJson(Map<String, dynamic> json) =>
      ReqBilling(
        billNo: json["billNo"],
        billingDate: json["billingDate"],
        showroomId: json["showroomId"],
        branchName: json["branchName"],
        name: json["name"],
        address: json["address"],
        deliveryDate: json["deliveryDate"],
        mobileNo: json["mobileNo"],
        instruction: json["instruction"],
        billingData: List<BillingDatum>.from(
            json["billingData"].map((x) => BillingDatum.fromJson(x))),
        total: json["total"],
        paymentType: json["paymentType"],
        advanceCash: json["advanceCash"],
        remaingCash: json["remaingCash"],
      );

  Map<String, dynamic> toJson() =>
      {
        "billNo": billNo,
        "billingDate": billingDate,
        "showroomId": showroomId,
        "branchName": branchName,
        "name": name,
        "address": address,
        "deliveryDate": deliveryDate,
        "mobileNo": mobileNo,
        "instruction": instruction,
        "billingData": List<dynamic>.from(billingData.map((x) => x.toJson())),
        "total": total,
        "paymentType": paymentType,
        "advanceCash": advanceCash,
        "remaingCash": remaingCash,
      };
}

class BillingDatum {
  String image;
  String modelNumber;
  String colorSelect;
  List<String> colors;
  List<String> designing;
  String designSelect;
  List<String> jackBase;
  String jackAndBaseSelect;
  List<String> footRest;
  String footrestSelect;
  String others1;
  String others2;
  String qty;
  String price;

  BillingDatum({
    required this.image,
    required this.modelNumber,
    required this.colorSelect,
    required this.colors,
    required this.designing,
    required this.designSelect,
    required this.jackBase,
    required this.jackAndBaseSelect,
    required this.footRest,
    required this.footrestSelect,
    required this.others1,
    required this.others2,
    required this.qty,
    required this.price,
  });

  factory BillingDatum.fromJson(Map<String, dynamic> json) =>
      BillingDatum(
        image: json["image"],
        modelNumber: json["modelNumber"],
        colorSelect: json["colorSelect"],
        colors: List<String>.from(json["colors"].map((x) => x)),
        designing: List<String>.from(json["designing"].map((x) => x)),
        designSelect: json["designSelect"],
        jackBase: List<String>.from(json["jackBase"].map((x) => x)),
        jackAndBaseSelect: json["jackAndBaseSelect"],
        footRest: List<String>.from(json["footRest"].map((x) => x)),
        footrestSelect: json["footrestSelect"],
        others1: json["others1"],
        others2: json["others2"],
        qty: json["qty"],
        price: json["price"],
      );

  Map<String, dynamic> toJson() =>
      {
        "image": image,
        "modelNumber": modelNumber,
        "colorSelect": colorSelect,
        "colors": List<dynamic>.from(colors.map((x) => x)),
        "designing": List<dynamic>.from(designing.map((x) => x)),
        "designSelect": designSelect,
        "jackBase": List<dynamic>.from(jackBase.map((x) => x)),
        "jackAndBaseSelect": jackAndBaseSelect,
        "footRest": List<dynamic>.from(footRest.map((x) => x)),
        "footrestSelect": footrestSelect,
        "others1": others1,
        "others2": others2,
        "qty": qty,
        "price": price,
      };
}
