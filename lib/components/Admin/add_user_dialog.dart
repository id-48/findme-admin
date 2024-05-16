import 'package:country_code_picker/country_code_picker.dart';
import 'package:file_selector/file_selector.dart';
import 'package:find_me_admin/models/user_model/get_user_profile.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/models/showroom/add_showroom/req_add_showroom.dart';
import 'package:find_me_admin/models/showroom/get_showroom/res_get_showroom.dart';
import 'package:find_me_admin/models/showroom/update_showroom/req_update_showroom.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/screens/Admin/get_users_screen.dart';
import 'package:find_me_admin/utils/Extensions/constants.dart';
import 'package:find_me_admin/utils/Extensions/string_extensions.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';
import 'package:image_picker/image_picker.dart';
import 'package:intl/intl.dart';
import 'package:multi_select_flutter/dialog/multi_select_dialog_field.dart';
import 'package:multi_select_flutter/util/multi_select_item.dart';
import 'package:multi_select_flutter/util/multi_select_list_type.dart';

import '../../main.dart';
import '../../models/user_model/res_get_all_user.dart';
import '../../utils/Colors.dart';
import '../../utils/Common.dart';
import '../../utils/Constants.dart';
import '../../utils/Extensions/app_textfield.dart';
import '../../utils/Extensions/colors.dart';
import '../../utils/Extensions/text_styles.dart';
import '../../widget/selected_image_viewer.dart';

class AddUserDialog extends StatefulWidget {
  static String tag = '/AddUserDialog';

  final User? userData;
  final Function()? onUpdate;

  AddUserDialog({this.onUpdate, this.userData});

  @override
  State<AddUserDialog> createState() => _AddUserDialogState();
}

class _AddUserDialogState extends State<AddUserDialog> {
  GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  TextEditingController userNameCont = TextEditingController();
  TextEditingController monoCont = TextEditingController();
  TextEditingController addressCont = TextEditingController();
  TextEditingController lattitudeCont = TextEditingController();
  TextEditingController longtitudeCont = TextEditingController();
  TextEditingController countryNameCont = TextEditingController();
  TextEditingController countryCodeCont = TextEditingController();
  TextEditingController ageCont = TextEditingController();
  TextEditingController emailCont = TextEditingController();
  TextEditingController bioCont = TextEditingController();
  TextEditingController genderCont = TextEditingController();
  TextEditingController lastActivateCont = TextEditingController();
  TextEditingController fcmTokenCont = TextEditingController();

  XFile? imageXFile;
  Uint8List? imgUint8list;
  String pickupCountryCode = defaultPhoneCode;
  List<String> lstSelectedLanguages = [];

  bool isUpdate = false;
  final borderRadius = BorderRadius.all(Radius.circular(9.0));

  @override
  void initState() {
    super.initState();
    init();
  }

  Future<void> init() async {
    isUpdate = widget.userData != null;

    if (isUpdate) {
      print('GET ::=lstSelectedLanguages == > ${widget.userData!.languages}');
      fcmTokenCont.text = widget.userData!.fcmToken.isNotEmpty ? widget.userData!.fcmToken : '';
      ageCont.text = widget.userData!.age.isNotEmpty ? widget.userData!.age : '';
      emailCont.text = widget.userData!.email.isNotEmpty ? widget.userData!.email : '';
      userNameCont.text = widget.userData!.name.isNotEmpty ? widget.userData!.name : '';
      bioCont.text = widget.userData!.bio.isNotEmpty ? widget.userData!.bio : '';
      monoCont.text = widget.userData!.mono.isNotEmpty ? widget.userData!.mono : '';
      lattitudeCont.text = widget.userData!.lattitude.isNotEmpty ? widget.userData!.lattitude : '';
      longtitudeCont.text = widget.userData!.longtitude.isNotEmpty ? widget.userData!.longtitude : '';
      countryCodeCont.text = widget.userData!.countryCode.isNotEmpty ? widget.userData!.countryCode : '';
      genderCont.text = widget.userData!.gender.isNotEmpty ? widget.userData!.gender : '';
      // addressCont.text=widget.userData!.address.isNotEmpty?widget.userData!.address:'';
      // lastActivateCont.text = DateFormat('dd-mm-yyyy').format(widget.userData!.lastActivate ?? DateTime.now());
      countryNameCont.text = widget.userData!.countryName.isNotEmpty ? widget.userData!.countryName : '';
      print('widget.userData!.profilePic:::${widget.userData!.profilePic.toString()}');
      if (widget.userData!.languages.isNotEmpty) {
        lstSelectedLanguages.addAll(widget.userData!.languages);
      }
      if (widget.userData!.profilePic.isNotEmpty) {
        imgUint8list = await imageDataURLtoUint8List(mBaseUrl + widget.userData!.profilePic[0]);
      }
      setState(() {});
    }
  }

  Future<void> getImage() async {
    imageXFile = await ImagePicker().pickImage(source: ImageSource.gallery);

    if (imageXFile!.path.isNotEmpty) {
      Uint8List image = await imageXFile!.readAsBytes();
      imgUint8list = image;
      setState(() {});
    }
  }

  AddUser() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);

      String fcmToken = fcmTokenCont.text.trim();
      String age = ageCont.text.trim();
      String email = emailCont.text.trim();
      String name = userNameCont.text.trim();
      String bio = bioCont.text.trim();
      String mono = monoCont.text.trim();
      String lattitude = lattitudeCont.text.trim();
      String longtitude = longtitudeCont.text.trim();
      String countryCode = countryCodeCont.text.trim();
      String gender = genderCont.text.trim();
      String address = addressCont.text.trim();
      // String lastActivate = lastActivateCont.text.trim();
      String countryName = countryNameCont.text.trim();

      await addUserData(
          context: context,
          fcmToken: fcmToken,
          age: age,
          email: email,
          name: name,
          bio: bio,
          mono: mono,
          lattitude: lattitude,
          longtitude: longtitude,
          countryCode: countryCode,
          gender: gender,
          address: address,
          lastActivate: DateTime.now().toIso8601String(),
          countryName: countryName,
          profilePic: imgUint8list != null ? [imgUint8list!] : [],
          lstSelectedLanguages: lstSelectedLanguages);
    }
  }

  UpdateUserApi() async {
    print('lstSelectedLanguages -------------:::${lstSelectedLanguages.toList()}');
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);
      String fcmToken = fcmTokenCont.text.trim();
      String age = ageCont.text.trim();
      String email = emailCont.text.trim();
      String name = userNameCont.text.trim();
      String bio = bioCont.text.trim();
      String mono = monoCont.text.trim();
      String lattitude = lattitudeCont.text.trim();
      String longtitude = longtitudeCont.text.trim();
      String countryCode = countryCodeCont.text.trim();
      String gender = genderCont.text.trim();
      String address = addressCont.text.trim();
      String lastActivate = DateTime.now().toIso8601String();
      String countryName = countryNameCont.text.trim();
      await updateUserData(
          context: context,
          userId: widget.userData!.id,
          fcmToken: fcmToken,
          age: age,
          email: email,
          name: name,
          bio: bio,
          mono: mono,
          lattitude: lattitude,
          longtitude: longtitude,
          countryCode: countryCode,
          gender: gender,
          address: address,
          lastActivate: lastActivate,
          countryName: countryName,
          profilePic: imgUint8list != null ? [imgUint8list!] : [],
          lstSelectedLanguages: lstSelectedLanguages);
    }
  }

  @override
  void setState(fn) {
    if (mounted) super.setState(fn);
  }

  @override
  Widget build(BuildContext context) {
    return AlertDialog(
      actionsPadding: EdgeInsets.only(right: 16, bottom: 16),
      title: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text(isUpdate ? 'Update User' : "Add User Details", style: boldTextStyle(color: primaryColor, size: 20)),
          IconButton(
            icon: Icon(Icons.close),
            padding: EdgeInsets.zero,
            onPressed: () {
              Navigator.pop(context, false);
            },
          ),
        ],
      ),
      content: Observer(builder: (context) {
        return SingleChildScrollView(
          child: Stack(
            children: [
              Visibility(
                visible: !appStore.isLoading,
                child: Form(
                  key: _formKey,
                  child: SizedBox(
                    width: ResponsiveWidget.isMediumScreen(context)
                        ? getBodyWidth(context)
                        : (getBodyWidth(context) - 48) * 0.4,
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        SizedBox(height: 16),
                        Text("User name", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: userNameCont,
                          textFieldType: TextFieldType.NAME,
                          decoration: commonInputDecoration(),
                          textInputAction: TextInputAction.next,
                          errorThisFieldRequired: "This field is required",
                        ),
                        SizedBox(height: 16),
                        Text("Mobile Number", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: monoCont,
                          textInputAction: TextInputAction.next,
                          textFieldType: TextFieldType.PHONE,
                          maxLength: 10,
                          decoration: commonInputDecoration(
                              suffixIcon: Icon(Icons.phone),
                              prefixIcon: IntrinsicHeight(
                                child: Row(
                                  mainAxisSize: MainAxisSize.min,
                                  children: [
                                    CountryCodePicker(
                                      initialSelection: pickupCountryCode,
                                      showCountryOnly: false,
                                      showFlag: true,
                                      showFlagDialog: true,
                                      showOnlyCountryWhenClosed: false,
                                      alignLeft: false,
                                      textStyle: primaryTextStyle(),
                                      dialogBackgroundColor: Theme.of(context).cardColor,
                                      barrierColor: Colors.black12,
                                      dialogTextStyle: primaryTextStyle(),
                                      searchDecoration: InputDecoration(
                                        iconColor: Theme.of(context).dividerColor,
                                        enabledBorder: UnderlineInputBorder(
                                            borderSide: BorderSide(color: Theme.of(context).dividerColor)),
                                        focusedBorder:
                                            UnderlineInputBorder(borderSide: BorderSide(color: primaryColor)),
                                      ),
                                      searchStyle: primaryTextStyle(),
                                      onInit: (c) {
                                        pickupCountryCode = c!.dialCode!;
                                      },
                                      onChanged: (c) {
                                        pickupCountryCode = c.dialCode!;
                                      },
                                    ),
                                    VerticalDivider(color: Colors.grey.withOpacity(0.5)),
                                  ],
                                ),
                              )),
                          validator: (value) {
                            if (value!.trim().isEmpty) {
                              return errorThisFieldRequired;
                            } else if (value.trim().length != 10) {
                              return error10digit;
                            }
                            return null;
                          },
                          inputFormatters: [
                            FilteringTextInputFormatter.digitsOnly,
                          ],
                        ),
                        SizedBox(height: 16),
                        Text("Address", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: addressCont,
                          textFieldType: TextFieldType.NAME,
                          decoration: commonInputDecoration(),
                          textInputAction: TextInputAction.next,
                          errorThisFieldRequired: "This field is required",
                        ),
                        SizedBox(height: 16),
                        Row(
                          children: [
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Email", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: emailCont,
                                    textFieldType: TextFieldType.EMAIL,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                            SizedBox(width: 10),
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Gender", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: genderCont,
                                    textFieldType: TextFieldType.NAME,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                          ],
                        ),
                        SizedBox(height: 16),
                        Row(
                          children: [
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Latitude", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: lattitudeCont,
                                    textFieldType: TextFieldType.NAME,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                            SizedBox(width: 10),
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Longitude", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: longtitudeCont,
                                    textFieldType: TextFieldType.NAME,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                          ],
                        ),
                        SizedBox(height: 16),
                        Row(
                          children: [
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Country Code", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: countryCodeCont,
                                    textFieldType: TextFieldType.NAME,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                            SizedBox(width: 10),
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Country Name", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: countryNameCont,
                                    textFieldType: TextFieldType.NAME,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                          ],
                        ),
                        SizedBox(height: 16),
                        Row(
                          children: [
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Bio", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: bioCont,
                                    textFieldType: TextFieldType.NAME,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                            SizedBox(width: 10),
                            Expanded(
                              child: Column(
                                crossAxisAlignment: CrossAxisAlignment.start,
                                children: [
                                  Text("Fcm Token", style: primaryTextStyle()),
                                  SizedBox(height: 8),
                                  AppTextField(
                                    controller: fcmTokenCont,
                                    textFieldType: TextFieldType.NAME,
                                    decoration: commonInputDecoration(),
                                    textInputAction: TextInputAction.next,
                                    errorThisFieldRequired: "This field is required",
                                  ),
                                ],
                              ),
                            ),
                          ],
                        ),
                        SizedBox(height: 16),
                        Text('Select Languages', style: primaryTextStyle()),
                        SizedBox(height: 5),
                        MultiSelectDialogField(
                          searchHint: "Languages",
                          validator: (value) {
                            if (value!.isEmpty) {
                              return 'Please select language!';
                            }
                            return null;
                          },
                          decoration: BoxDecoration(
                              borderRadius: BorderRadius.circular(25), border: Border.all(color: Color(0xFFB3B3B3))),
                          title: Row(
                            mainAxisAlignment: MainAxisAlignment.spaceBetween,
                            children: [
                              Text("Select Languages", style: TextStyle(color: primaryColor, fontSize: 20)),
                              IconButton(
                                icon: Icon(Icons.close),
                                padding: EdgeInsets.zero,
                                onPressed: () {
                                  Navigator.pop(context, false);
                                },
                              ),
                            ],
                          ),
                          dialogWidth: 500,
                          dialogHeight: 500,
                          checkColor: Colors.white,
                          selectedColor: primaryColor,
                          items: lstLanguages.map((String e) => MultiSelectItem(e, e)).toList(),
                          listType: MultiSelectListType.LIST,
                          initialValue: lstSelectedLanguages,
                          onConfirm: (values) {
                            lstSelectedLanguages.clear();
                            lstSelectedLanguages.addAll(values);
                            setState(() {});
                          },
                        ),
                        SizedBox(height: 16),
                        Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          mainAxisSize: MainAxisSize.min,
                          children: [
                            Text("Add Image", style: primaryTextStyle()),
                            SizedBox(height: 16),
                            SizedBox(
                              width: 120,
                              height: 40,
                              child: ElevatedButton(
                                style: ElevatedButton.styleFrom(
                                    shape: RoundedRectangleBorder(
                                        borderRadius: BorderRadius.circular(8.0),
                                        side: BorderSide(color: viewLineColor)),
                                    elevation: 0,
                                    backgroundColor: Colors.transparent,
                                    shadowColor: Colors.transparent),
                                child: Text("Select File", style: boldTextStyle(color: Colors.grey)),
                                onPressed: () {
                                  getImage();
                                },
                              ),
                            ),
                            SizedBox(height: 10),
                            SelectedImageViewer(res: imgUint8list != null ? [imgUint8list!] : [], setState: setState),
                            SizedBox(height: 16),
                          ],
                        ),
                      ],
                    ),
                  ),
                ),
              ),
              Visibility(visible: appStore.isLoading, child: loaderWidget()),
            ],
          ),
        );
      }),
      actions: <Widget>[
        dialogSecondaryButton("Cancel", () {
          Navigator.pop(context, false);
        }),
        SizedBox(width: 4),
        dialogPrimaryButton(isUpdate ? "Update" : "Add", () {
          isUpdate ? UpdateUserApi() : AddUser();
        }),
      ],
    );
  }
}
// title
// location
// lattitude
// longtitude
// eventDate
// time
// description
// mono
